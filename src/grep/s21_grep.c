#include "s21_grep.h"

int main(int argc, char** argv) {
  int status = grep_programm(argc, argv);
  return status;
}

int grep_programm(int argc, char** argv) {
  Configuration config;
  memset(&config, 0, sizeof(Configuration));
  char pattern[PATTERN_SIZE];
  pattern[0] = '\0';
  int status = extract_param(argc, argv, pattern, &config);
  regex_t result_pattern;
  if (status == 0) status = generate_pattern(pattern, &result_pattern, &config);
  for (int i = (argc - config.num_files); i < argc && status == 0; i++)
    process_file(argv[i], &result_pattern, &config);
  free_everything(&result_pattern);
  return status;
}

int generate_pattern(const char* pattern, regex_t* result_pattern,
                     Configuration* config) {
  int status = 0;
  int regflag = config->i_ignore_case ? REG_ICASE : REG_EXTENDED;
  status = regcomp(result_pattern, pattern, regflag);
  if (status != 0) fprintf(stderr, "Error compiling regex\n");
  return status;
}

int extract_param(int argc, char** argv, char* pattern, Configuration* config) {
  int opt, pattern_count = 0, status = 0;
  struct option* long_options = get_long_options();
  while ((opt = getopt_long(argc, argv, "e:ivcln", long_options, NULL)) != -1 &&
         status == 0) {
    switch (opt) {
      case 'e':
        config->e_pattern = 1;
        pattern_count++ > 0 ? strcat(pattern, "|") : (void)0;
        strcat(pattern, optarg);
        break;
      case 'i':
        config->i_ignore_case = 1;
        break;
      case 'v':
        config->v_invert_match = 1;
        break;
      case 'c':
        config->c_count_of_matching_lines = 1;
        break;
      case 'l':
        config->l_output_matching_files = 1;
        break;
      case 'n':
        config->n_number_matching_lines = 1;
        break;
      case '?':
        fprintf(stderr,
                "usage: grep [-ivcln] [-e pattern] [pattern] [file ...]\n");
        status = 1;
    }
  }
  if (!config->e_pattern && status == 0) strcpy(pattern, argv[optind++]);
  if (status == 0) config->num_files = argc - optind;
  return status;
}

struct option* get_long_options() {
  static struct option long_options[] = {
      {"regexp", required_argument, 0, 'e'},
      {"ignore-case", no_argument, 0, 'i'},
      {"invert-match", no_argument, 0, 'v'},
      {"count", no_argument, 0, 'c'},
      {"files-with-matches", no_argument, 0, 'l'},
      {"line-number", no_argument, 0, 'n'},
      {0, 0, 0, 0}};
  return long_options;
}

void process_file(const char* filename, regex_t* pattern,
                  Configuration* config) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "grep: %s: No such file or directory\n", filename);
    return;
  }
  char line[LINE_SIZE];
  int line_number = 0;
  int line_counter = 0;
  while (fgets(line, sizeof(line), file))
    process_line(filename, line, ++line_number, &line_counter, pattern, config);
  fclose(file);
  if (config->c_count_of_matching_lines) {
    if (config->num_files > 1)
      printf("%s:%d\n", filename, line_counter);
    else
      printf("%d\n", line_counter);
  }
  if (config->l_output_matching_files && line_counter > 0)
    printf("%s\n", filename);
}

void process_line(const char* filename, char* line, int line_number,
                  int* line_counter, regex_t* pattern, Configuration* config) {
  int match = check_if_match(line, pattern);
  if (config->v_invert_match) {
    match = !match;
  }
  if (match) {
    ++(*line_counter);
    if (!config->c_count_of_matching_lines && !config->l_output_matching_files)
      print_lines(filename, line, line_number, config);
  }
}

int check_if_match(const char* line, regex_t* pattern) {
  return (regexec(pattern, line, 0, NULL, 0) == 0);
}

void print_lines(const char* filename, const char* line, int line_number,
                 Configuration* config) {
  if (config->num_files > 1) printf("%s:", filename);
  if (config->n_number_matching_lines) printf("%d:", line_number);
  printf("%s", line);
  size_t len = strlen(line);
  if (len > 0 && line[len - 1] != '\n') printf("\n");
}

void free_everything(regex_t* pattern) {
  if (pattern != NULL) regfree(pattern);
}