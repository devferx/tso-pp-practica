#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void err_quit(char *msg);
const char *mostrarDirectorio();
void listarDirectorio(char *path[]);
void mostrarArchivo(char *nombreArchivo);
void cambiarDirectorio(char *path[]);

int main(int argc, char *argv[])
{
  // if (argc > 1)
  // {
  // }
  // else
  // {
  //   printf("Necesito argumento\n");
  // }

  // Ejercicio 1
  printf(">>>>>> Ejercicio 1 <<<<<<\n");
  printf("Directorio de trabajo actual: %s", mostrarDirectorio());
  printf("\n");

  // Ejercicio 2
  printf(">>>>>> Ejercicio 2 <<<<<<\n");
  listarDirectorio(argv[1]);

  // Ejercicio 3
  printf(">>>>>> Ejercicio 3 <<<<<<\n");
  cambiarDirectorio(argv[2]);

  // Ejercicio 4
  printf(">>>>>> Ejercicio 4 <<<<<<\n");
  mostrarArchivo(argv[3]);
}

void err_quit(char *msg)
{
  perror(msg);
  exit(EXIT_FAILURE);
}

const char *mostrarDirectorio()
{
  char wd[1000];
  char *res = getcwd(wd, sizeof(wd));

  return res;
}

// void listarDirectorio(int argc, char *argv[])
void listarDirectorio(char *path[])
{
  DIR *dir;
  struct dirent *mydirent;
  int i = 1;

  if ((dir = opendir(path)) == NULL)
    err_quit("opendir");

  printf("Contenido del directorio seleccionado: \n");

  while ((mydirent = readdir(dir)) != NULL)
    printf("%3d : %s\n", i++, mydirent->d_name);

  closedir(dir);
}

void mostrarArchivo(char *nombreArchivo)
{
  FILE *ptr;
  char ch;

  // Opening file in reading mode
  ptr = fopen(nombreArchivo, "r");

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
}

void cambiarDirectorio(char *path[])
{
  printf("Cambiando a directorio: %s", path);
  printf("\n");

  if (chdir(path) < 0)
  {
    perror("chdir");
    exit(EXIT_FAILURE);
  }
  mostrarDirectorio();
  // system("ls");
  char *currentDir = mostrarDirectorio();
  printf("Directorio de trabajo actual: %s", currentDir);
  printf("\n");
}
