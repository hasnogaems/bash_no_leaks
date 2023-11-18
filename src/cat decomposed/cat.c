#include <stdio.h>
#include <string.h>


/**void print_file(char *filename) {
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

    

}**/
int s(char *filename){
    FILE *fp;
    int double_empty_string=0;
    int enter=0;
    fp = fopen(filename, "r");
    int c;
    while(1){
        c=fgetc(fp);
        if(feof(fp)){
            break;
        }
        if(c==10&&enter==2)
        double_empty_string++;
        if(c==10&&enter<2)
        enter++;
        

    }
    fclose(fp);
        return double_empty_string-1;
}

void print_file(char *filename, int flag_b, int flag_e, int flag_s) {
    FILE *fp;
    fp = fopen(filename, "r"); //opens file for reading
    int c;
    int double_empty_string=s(filename);
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
        
        if(flag_s==1&&c==10&&double_empty_string>0){
        printf("");
        double_empty_string--;}
        else
        printf("%c", c);
        
        if(flag_b==1){
        if(c==10){
            printf("%d ", count+1);
            ++count;}}
    }
    fclose(fp);
printf("double_empty_string=%d", double_empty_string);
   

}


int main(int argc,char *argv[]){
    int flag_b, flag_e,flag_s;
    flag_b=flag_e=flag_s=0;
    for(int k=1;k<argc;k++){

    if(strcmp(argv[k],"-b")==0)flag_b=1;
    if(strcmp(argv[k],"-e")==0)flag_e=1;
    if(strcmp(argv[k],"-s")==0)flag_s=1;}
    print_file(argv[argc-1], flag_b, flag_e, flag_s);
    return 0;

}