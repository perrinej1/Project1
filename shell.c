#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tokenize.h"
#include <sys/wait.h>

int main(int argc, char **argv)
{
  for(;;)
  {
    int tokenc;   //initializing tokenc for later
    char **tokenv;    //initializing tokenv for later

    char *input;    //string to hold line
    input = malloc(sizeof(char) * 200);   //dynamically allocating string.

    printf("Enter shell: ");
    //gets input text and checks if EOF is entered, if so breaks
    if(!fgets(input, sizeof(char) * 200, stdin))
    {
      return 0;
    };
    tokenize(input, &tokenc, &tokenv);   //calling tokenize function

    int pid;
    pid = fork();   //creating child process

    //if 0, pid is child
    //if not 0, pid is parent
    if(pid == 0)
    {
      //runs execv and the program in the arguments, and if the program dosn't
      //exist, then it prints error and exits.
      if(execvp(tokenv[0], tokenv))
      {
        printf("execv did not work due to this: error %d %s\n",errno,strerror(errno));
        exit(0);
      }
    }
    else
    {
      wait(NULL);
    }

    free(input);    //deallocate heap space
    input = NULL;   //setting pointer back to null
  }
}
