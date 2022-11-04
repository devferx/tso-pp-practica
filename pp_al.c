#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const char *mostrarDirectorio();
void listarDirectorio(char *path[]);
void mostrarArchivo(char *nombreArchivo);
void cambiarDirectorio(char *path[]);
int countCharacter(char *str, char c);
void err_quit(char *msg);

int main(int argc, char *argv[])
{
  while (1)
  {
    char *str[256];
    printf("comando a ejecutar:");
    fgets(str, 256, stdin);

    char *comando = strtok(str, " ");

    comando[strlen(comando) - 1] = '\0';

    if (strcmp(comando, "exit") == 0)
    {
      break;
    }
    else if (strcmp(comando, "pwd") == 0)
    {
      printf("Directorio de trabajo actual: %s\n", mostrarDirectorio());
    }
    else if (strcmp(comando, "ls") == 0)
    {
      listarDirectorio(mostrarDirectorio());
    }
    else if (strcmp(comando, "c") == 0)
    {
      char *path = strtok(NULL, " ");
      path[strlen(path) - 1] = '\0';
      cambiarDirectorio(path);
    }
    else if (strcmp(comando, "ca") == 0)
    {
      char *nombreArchivo = strtok(NULL, " ");
      nombreArchivo[strlen(nombreArchivo) - 1] = '\0';
      mostrarArchivo(nombreArchivo);
    }
    else
    {
      printf("comando no reconocido\n");
    }
  }
}

int countCharacter(char *str, char c)
{
  int count = 0;
  for (int i = 0; i < strlen(str); i++)
  {
    if (str[i] == c)
    {
      count++;
    }
  }
  return count;
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
