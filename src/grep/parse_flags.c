#include "h.h"
#include <string.h>
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
int parse_pattern( int argc, char **argv){
    

    int i;
    char **e_ptrns=(char **)malloc(1025*sizeof(char));
    int count=1;
    for(i=1;i<argc-1;i++){
        if(strcmp(argv[i], "-e")==0){
        printf("-e detected!");
        e_ptrns[count-1]=argv[i+1];
        count++;realloc(e_ptrns, count*(1025*sizeof(char)));}

        if(argv[i][0]!='-'&&strcmp(argv[i-1], "-e")!=0)
        break;

    }
    printf("e_ptrn=%s", e_ptrns[0]);
return i;
}

int parse_file_name(int y, char **argv, int argc){
    int i;
    for(i=y+1;i<argc-1;i++){
        if(argv[i][0]!='-')
        break;
    }
    return i;

}