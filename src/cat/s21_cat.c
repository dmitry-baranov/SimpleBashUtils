#include "s21_cat.h"

int main(int argc, char** argv) {
  int status = cat_programm(argc, argv);
  return status;
}

int cat_programm(int argc, char* argv[]) {
  Configuration config;
  memset(&config, 0, sizeof(Configuration));
  int status = extract_param(argc, argv, &config);
  for (int i = (argc - config.num_files); i < argc && status == 0; i++) {
    process_file(argv[i], &config);
  }
  return status;
}

void process_file(const char* filename, Configuration* config) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "cat: %s: No such file or directory\n", filename);
    return;
  }
  char line[LINE_SIZE];
  int line_number = 0;
  int line_number_non_empty = 0;
  int previous_is_blank = 0;
  while (fgets(line, sizeof(line), file)) {
    process_line(line, ++line_number, &line_number_non_empty,
                 &previous_is_blank, config);
  }
  fclose(file);
}

void process_line(char* line, int line_number, int* line_number_non_empty,
                  int* previous_is_blank, Configuration* config) {
  int is_blank = !strcmp(line, "\n");
  if (config->s_squeeze_blank && is_blank && *previous_is_blank)
    return;
  else if (is_blank)
    *previous_is_blank = 1;
  else
    *previous_is_blank = 0;
  if (config->n_number_all_lines)
    printf("%6d\t", line_number);
  else if (config->b_number_non_empty && !is_blank)
    printf("%6d\t", ++(*line_number_non_empty));
  for (int i = 0; i < (int)strlen(line); i++) {
    process_each_symbol(line[i], config);
  }
}

void process_each_symbol(char symbol, Configuration* config) {
  if (config->v_display_nonprinting && symbol != 9 && symbol != 10 &&
      symbol <= 31) {
    printf("^");
    symbol += 64;
  } else if (config->v_display_nonprinting && symbol == 127) {
    printf("^");
    symbol = 63;
  }
  if (config->t_display_tabs && symbol == 9) {
    printf("^");
    symbol = 73;
  }
  if (symbol == 10 && config->e_end_of_line) printf("$");
  printf("%c", symbol);
}

int extract_param(int argc, char** argv, Configuration* config) {
  int opt, status = 0;
  static struct option long_options[] = {
      {"number-nonblank", no_argument, 0, 'b'},
      {"number", no_argument, 0, 'n'},
      {"squeeze-blank", no_argument, 0, 's'},
      {0, 0, 0, 0}};

  while ((opt = getopt_long(argc, argv, "benstvET", long_options, NULL)) !=
             -1 &&
         status == 0) {
    switch (opt) {
      case 'b':
        config->b_number_non_empty = 1;
        break;
      case 'e':
        config->e_end_of_line = 1;
        config->v_display_nonprinting = 1;
        break;
      case 'E':
        config->e_end_of_line = 1;
        break;
      case 'n':
        config->n_number_all_lines = 1;
        break;
      case 's':
        config->s_squeeze_blank = 1;
        break;
      case 't':
        config->t_display_tabs = 1;
        config->v_display_nonprinting = 1;
        break;
      case 'T':
        config->t_display_tabs = 1;
        break;
      case 'v':
        config->v_display_nonprinting = 1;
        break;
      case '?':
        fprintf(stderr, "usage: cat [-benstvET] [file ...]\n");
        status = 1;
    }
  }
  if (status == 0) config->num_files = argc - optind;
  return status;
}
