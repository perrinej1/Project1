#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int arc, char **argv)
{
    // Initiating strings to be read
    char str;
    char *new_str = NULL;
    int i = 0;

    // Infinite loop to keep reading lines
    for(;;)
    {
      printf("Enter text here: ");

      // Reads characters of the line until it reaches the end
      while (str != '\0')
      {
        // Gets each character from line
        str = getc(stdin);

        // If control-d is entered, then goes here and closes
        if(str == EOF)
        {
          free(new_str);
          new_str = NULL;
          return 0;
        }

        // Prints out each character
        putc(str, stdout);
      }
      printf("\n");
    }
}
