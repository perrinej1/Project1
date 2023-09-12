#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
  //runs execv and the program in the arguments, and if the program dosn't
  //exist, then it prints error and terminates.
  if(execv(argv[1], argv))
  {
    printf("execv did not work due to this: error %d %s\n",errno,strerror(errno));
    return 0;
  }
}
