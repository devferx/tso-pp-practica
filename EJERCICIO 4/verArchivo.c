// Ejercio 4 TSO 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Driver code
int main(int argc, char *argv[])
{
  FILE *ptr;
  char ch;

  // Opening file in reading mode
  ptr = fopen("hilo2.c", "r");

  if (NULL == ptr)
  {
    printf("file can't be opened \n");
  }

  printf("content of this file are \n");

  // Printing what is written in file
  // character by character using loop.
  do
  {
    ch = fgetc(ptr);
    printf("%c", ch);

    // Checking if character is not EOF.
    // If it is EOF stop eading.
  } while (ch != EOF);

  // Closing the file
  fclose(ptr);
  return 0;
}
