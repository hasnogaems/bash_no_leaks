#ifndef HEADERS_H
#define HEADERS_H
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

typedef struct Flags {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;  
  int s;
  int file;
  int o;
  int count;
  int f;
  char pattern[10000];
  int file_counter;
} Flags;

static struct option long_options[] = {{"number-nonblank", no_argument, 0, 'b'},
                                       {0, 0, 0, 0}};
int regex(char pattern[], char line[], Flags);
int parse_pattern(int argc, char **argv, int *);
int parse_file_amount(char **argv, int argc);
Flags parse_flags(int argc, char **argv, char*);
int open_file_and_i_flag(FILE** fp,Flags* flag, int file_name, char** argv, int* eflags);
int grep(Flags flag,FILE* fp, int eflags, char* line_, char** argv, int y, int count, int file_amount, char** f_ptrns, int* fcount, int argc);
void noflags_ve_v(Flags flag, FILE* fp, int* count, int eflags, int x, char* line_, char** argv, int y, int file_amount, char** f_ptrns, int* f_count, int argc);
void multifileprint(Flags* flag, char* filename);
void flag_e(Flags flag, FILE* fp, int* count, int eflags, char* line_, char** argv, int file_amount, int argc);
void flag_o(char* line_, char pattern[], Flags flag);
void pattern_from_file(char* line_, Flags* flag);
void flag_f(Flags flag, FILE* fp, int* f_count, char*** f_ptrns, int eflags, char* line_,char**  argv, int file_amount);
void add_pattern(char *pattern, Flags* flag);
#endif
