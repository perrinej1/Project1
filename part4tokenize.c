#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tokenize(char *input, int *token_count, char ***token_vector)
{
  //int i = 0;

  char *whitespace = " \t";   //creates new token for every space or tab

  char *token;    //reads next tokens
  char *line;   //line to read tokens
  line = malloc(sizeof(char) * 200);

  line = input;   //sets line to input
  token = strtok(line, whitespace);   //finding first tokenc

  //looping over input until all tokens are found
  while(token != NULL)
  {
    printf("%s\n", token);    //prints token then new line
    token = strtok(NULL, whitespace);   //finding next token
  }
  return 0;
}
