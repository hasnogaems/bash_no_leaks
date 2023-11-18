#include <stdio.h>
int main(int argc, char *argv[]){
    FILE *fp;
    const char *arrayofwords[300];
    int wordcount;
    char ch;
    fp=fopen("test.txt", "r");
    if(fp!=NULL){
        while (!feof(fp)){
            fscanf(fp, "%s",&arrayofwords[wordcount]);
            wordcount++;
        }
    puts("");
    for (int i=0; i<(wordcount-1); i++) {
        puts(arrayofwords[i]);
    }    
    puts("");
    }else{
        puts("Cannot read the file!");
    }
    return 0;
            }
    

