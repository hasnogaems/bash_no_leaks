#ifndef PARSE_FLAGS_H
#define PARSE_FLAGS_H
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
typedef struct flags{
    int b;
    int e;
    int n;
    int s;
    int t;
    int E;
    int T;
    int v;

    //if(b==e==n==s==t==0)

  }flags;
  static struct option long_options[] = {
            {"number-nonblank", no_argument, 0, 'b'},
            {"number", no_argument, 0, 'n'},
            {"squeeze-blank", no_argument, 0, 's'},
            {0, 0, 0, 0}
        };
flags parse_flags(int argc, char **argv);
int extralines(FILE *fp);
void big_while(int argc, char **argv, FILE *fp, flags* Flag);
int v_and_s(int* previous, int* current, flags* Flag,int* c, int* count);
int flag_e(flags* Flag, int* c);
void argc1(int* c);
#endif