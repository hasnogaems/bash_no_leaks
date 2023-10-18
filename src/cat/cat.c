#include <stdio.h>
#include <string.h>


void print_file(char *filename) {
    FILE *fp;
    int c;
    fp = fopen(filename, "r"); //opens file for reading
    while(1) {
        c=fgetc(fp);
        if( feof(fp) ) {
            break;
        }
        printf("%c", c);
    }
    fclose(fp);

    

}

void print_b(char *filename, int flag_b, int flag_e) {
    FILE *fp;
    fp = fopen(filename, "r"); //opens file for reading
    int c;
    int count=1;
    if(flag_b==1){
    printf("%d ", count);}
    while(1) {
        c=fgetc(fp);
        if( feof(fp) ) {
            break;
        }
        
        if(flag_e==1){
            if(c==10)
            printf("%%");
        }
        printf("%c", c);
        
        if(flag_b==1){
        if(c==10){
            printf("%d ", count+1);
            ++count;}}
    }
    fclose(fp);

   

}


int main(int argc,char *argv[]){
    int flag_b, flag_e;
    flag_b=flag_e=0;
    for(int k=1;k<argc;k++){

    if(strcmp(argv[k],"-b")==0)flag_b=1;
    if(strcmp(argv[k],"-e")==0)flag_e=1;}
    print_b(argv[argc-1], flag_b, flag_e);
    return 0;

}