#ifndef HEADERS_H
#define HEADERS_H
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
typedef struct Flags{
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
    
}Flags;

static struct options long_options[]={
    {"number-nonblank", no_argument, 0, 'b'},
    {0, 0, 0, 0}
};
int regex(char x[], char y[]);

#endif