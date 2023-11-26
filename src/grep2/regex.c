#include <regex.h>
#include <stdio.h>
#include "h.h"
int regex(char pattern[], char line[], int eflags, Flags flag, regmatch_t* matches[]) {
  regex_t regex;
  // printf("%d", eflags);// тут лезли нули
  
  int return_value = regcomp(&regex, pattern, eflags);
  if (return_value) {
    printf("Could not compile regular expression.\n");
    return 1;
  }
  if(flag.o!=1){
  return_value = regexec(&regex, line, 0, NULL, 0);
  if (!return_value) {
  } else {
    // printf("%dNo match.\n",return_value);
  }
  regfree(&regex);}
  else{
  return_value = regexec(&regex, line, 0, NULL, 0);
  if (!return_value) {
  } else {
    // printf("%dNo match.\n",return_value);
  }
  regfree(&regex);  

  }
  return return_value;
}
