#include "h.h"
Flags parse_flags(int argc, char **argv){
    int c;
    Flags flag={0};
    int option_index=0;
    
    if(argc>1){
        while(1){
        c = getopt_long(argc, argv, "+eivclnhsfo", long_options, &option_index);
        if (c == -1)
        break;
    
    switch(c){
        case 'e':
        flag.e=1;
        break;
        case 'i':
        flag.i=1; 
        break;   
        case 'v':
        flag.v=1;
        break;
        case 'c':
        flag.c=1;
        break;
        case 'l':
        flag.l=1;
        break;
        case 'n':
        flag.n=1;
        break;
        case 'h':
        flag.h=1;
        break;
        case 's':
        flag.s=1;
        break;
        case 'f':
        flag.file=1;
        break;
        case 'o':
        flag.o=1;
        break;
        
    }
    return flag;
}
    }
}