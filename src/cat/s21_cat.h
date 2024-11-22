#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_SIZE 1024

typedef struct {
  int b_number_non_empty;
  int e_end_of_line;
  int n_number_all_lines;
  int s_squeeze_blank;
  int t_display_tabs;
  int v_display_nonprinting;
  int num_files;
} Configuration;

int cat_programm(int argc, char* argv[]);
void process_file(const char* filename, Configuration* config);
void process_line(char* line, int line_number, int* line_number_non_empty,
                  int* previous_is_blank, Configuration* config);
int extract_param(int argc, char** argv, Configuration* config);
void process_each_symbol(char symbol, Configuration* config);