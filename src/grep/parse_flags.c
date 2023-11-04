#include "headers.h"
Flags parse_flags(int argc, char **argv){
    int c;
    Flags flag={0};
    
    if(argc>1){
        while(1){
        c = getopt(argc, argv, "+eivclnhsfo");
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
        flag.f=1;
        break;
        case 'o':
        flag.o=1;
        break;
        
    }
    return flag;
}
    }
}