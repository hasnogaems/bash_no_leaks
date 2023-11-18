#include <stdio.h>
#include <regex.h>
int main(){
    char pattern[]="[a-z]";
    char line[]="abcsfsfsfgsgab";
    regex_t regex;
    int return_value = regcomp(&regex, pattern, 0);
    if(return_value) {
        printf("Could not compile regular expression.\n");
        return 1;
    }

    return_value = regexec(&regex, line, 0, NULL, 0);
    if(!return_value){
        printf("%dMatch.\n", return_value);
    }else{
        printf("%dNo match.\n",return_value);

    }
    regfree(&regex);
    return 0;
    }

