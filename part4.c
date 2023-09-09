#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenize.h"

int main(int argc, char **argv)
{
  int tokenc;   //initializing tokenc for later
  char **tokenv;    //initializing tokenv for later

  char *input;    //string to hold line
  input = malloc(sizeof(char) * 200);   //dynamically allocating string.

  printf("Input text: ");
  fgets(input, sizeof(char) * 200, stdin);   //getting input from user

  tokenize(input, &tokenc, &tokenv);   //calling tokenize function

  free(input);    //deallocate heap space
  input = NULL;   //setting pointer back to null

  return 0;
}
