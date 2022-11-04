#include <unistd.h>
#include <stdio.h>
int main()
{
	char wd[1000];
	printf("Directorio de trabajo actual: %s",getcwd(wd,sizeof(wd)));
}
