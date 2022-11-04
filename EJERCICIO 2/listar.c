//Usado para el flujo de entrada/salida basico
#include <stdio.h>
//Usado para manejar archivos de directorio
#include <dirent.h>
//Para códigos de SALIDA y manejo de errores
#include <errno.h>
#include <stdlib.h>

void listar(const char *dir,int op_a,int op_l)
{
	////aqui vamos a listar el directorio
	struct dirent *d;
	DIR *dh = opendir(dir);
	if (!dh)
	{
		if (errno = ENOENT)
		{
			//Si el directorio no se encuentra
			perror("El directorio no existe");
		}
		else
		{
		//Si el directorio no es legible, arroja un error y sal
			perror("No se puede leer el directorio");
		}
		exit(EXIT_FAILURE);
	}
	//Si bien la siguiente entrada no se puede leer, imprimiremos archivos de directorio
	while ((d = readdir(dh)) != NULL)
	{
		//Si se encuentran archivos ocultos continuamos
		if (!op_a && d->d_name[0] == '.')
			continue;
		printf("%s  ", d->d_name);
		if(op_l) printf("\n");
	}
	if(!op_l)
	printf("\n");
}

int main(int argc, const char *argv[])
{
	if (argc == 1)
	{
		listar(".",0,0);
	}
	else if (argc == 2)
	{
		if (argv[1][0] == '-')
		{
			//Comprobando si se pasa la opción
			//Opciones de apoyo: a, l
			int op_a = 0, op_l = 0;
			char *p = (char*)(argv[1] + 1);
			while(*p){
				if(*p == 'a') op_a = 1;
				else if(*p == 'l') op_l = 1;
				else{
					perror("Opcion no disponible");
					exit(EXIT_FAILURE);
				}
				p++;
			}
			listar(".",op_a,op_l);
		}
	}
	return 0;
}
