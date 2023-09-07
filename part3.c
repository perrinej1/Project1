//UNIX programs will always have at least one argument because you have to
//call the file, so there will always be ./file_name

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  // Setting up loop to iterate over and print command line arguments
  int i;
  for(i = 0; i < argc; i++)
  {
    // Prints argument and creates new line
    printf(argv[i]);
    printf("\n");
  }
  exit(0);
}
