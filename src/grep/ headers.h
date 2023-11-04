#ifndef HEADERS_H
#define HEADERS_H
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
typedef stuct Flags{
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

static struct option long_options[]{
 {0 , 0 , 0 , 0}   
}
#endif