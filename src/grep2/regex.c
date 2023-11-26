#include <regex.h>
#include <stdio.h>
int regex(char pattern[], char line[], int eflags) {
  // printf("%d", eflags);// тут лезли нули
  regex_t regex;
  int return_value = regcomp(&regex, pattern, eflags);
  if (return_value) {
    printf("Could not compile regular expression.\n");
    
  }

  return_value = regexec(&regex, line, 0, NULL, 0);
  if (!return_value) {
  } else {
    // printf("%dNo match.\n",return_value);
  }
  regfree(&regex);
  return return_value;
}
