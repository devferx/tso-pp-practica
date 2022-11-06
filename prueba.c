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

  if (argc < 4)
    err_quit("Faltan argumentos: pp <comando> <path> <nombreArchivo>");

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

const char *mostrarDirectorio()
{
  char wd[1000];
  char *res = getcwd(wd, sizeof(wd));

  return res;
}

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

  ptr = fopen(nombreArchivo, "r");

  if (NULL == ptr)
    printf("El archivo no se puede mostrar \n");

  printf("El contenido del archivo es: \n");
  do
  {
    ch = fgetc(ptr);
    printf("%c", ch);
  } while (ch != EOF);

  fclose(ptr);
}

void cambiarDirectorio(char *path[])
{
  char *currentDir = mostrarDirectorio();
  printf("Directorio actual: %s \n", currentDir);
  printf("Cambiando a directorio: %s \n", path);

  if (chdir(path) < 0)
    err_quit("chdir");

  mostrarDirectorio();

  currentDir = mostrarDirectorio();
  printf("Directorio de trabajo actual: %s \n", currentDir);
}

void err_quit(char *msg)
{
  perror(msg);
  exit(EXIT_FAILURE);
}
