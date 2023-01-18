#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		printf("\nПамятка для тех кто здесь впервые!!!\n\nЗапустите исполянемый файл с флагом --help для справки\n\nНапрмер:\n ./filename --help\n\n");
		return 0;
	}
	if (!strcmp(argv[1], "--help"))
	{
		FILE *file = fopen("help.txt", "r");
		char str[255];
		while (fgets(str, 255, file) != NULL)
    	{
        	printf("%s", str);
    	}
		fclose(file);
		return 0;
	}
	if (argc % 2 == 0)
	{
		printf("ERROR!!!\n");
		return 0;
	}


	return 0; 
}