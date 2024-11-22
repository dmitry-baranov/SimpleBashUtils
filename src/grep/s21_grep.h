#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_SIZE 1024
#define PATTERN_SIZE 128

typedef struct {
  int e_pattern;
  int i_ignore_case;
  int v_invert_match;
  int c_count_of_matching_lines;
  int l_output_matching_files;
  int n_number_matching_lines;
  int num_files;
} Configuration;

int grep_programm(int argc, char** argv);
int extract_param(int argc, char** argv, char* pattern, Configuration* config);
void process_file(const char* filename, regex_t* pattern,
                  Configuration* config);
int check_if_match(const char* line, regex_t* pattern);
void process_line(const char* filename, char* line, int line_number,
                  int* line_counter, regex_t* pattern, Configuration* config);
int generate_pattern(const char* pattern, regex_t* result_pattern,
                     Configuration* config);
struct option* get_long_options();
void print_lines(const char* filename, const char* line, int line_number,
                 Configuration* config);
Configuration* create_configuration();
void free_everything(regex_t* pattern);