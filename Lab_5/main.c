#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char **argv)
{

	//Разбираемся с флагами


	//Пустой ввод
	if (argc <= 1)
	{
		printf("\nПамятка для тех кто здесь впервые!!!\n\nЗапустите исполянемый файл с флагом --help для справки\n\nНапрмер:\n ./filename --help\n\n");
		return 0;
	}

	//Флаг --help
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

	//Если флаги были криво введены
	if ((argc < 6) || (argc >= 7) )
	{
		printf("ERROR!!!\n");
		return 0;
	}


	FILE *input = fopen(argv[1], "r");
	char buf[255];
	while (fgets(buf, 255, input) != NULL)
    	{
        	printf("%s", buf);
    	}
	fclose(input);







	return 0; 
}