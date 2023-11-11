#include <stdio.h>
#include <regex.h>
int regex(char pattern[], char line[]){
    
    regex_t regex;
    int return_value = regcomp(&regex, pattern, 0);
    if(return_value) {
        printf("Could not compile regular expression.\n");
        return 1;
    }

    return_value = regexec(&regex, line, 0, NULL, 0);
    if(!return_value){
        
    }else{
       // printf("%dNo match.\n",return_value);

    }
    regfree(&regex);
    return return_value;
    }

