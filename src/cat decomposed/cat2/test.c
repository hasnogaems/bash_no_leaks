#include <stdio.h>

//int extralines(FILE *fp);
int main(){
    FILE *fp=fopen("test.txt", "r");
    int x=extralines(fp);
    return 0;
}
