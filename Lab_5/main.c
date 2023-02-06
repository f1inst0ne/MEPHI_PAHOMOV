#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(int argc, char *argv[])
{

	//--help
	if (argc > 1)
	{
		if (strcmp(argv[1], "--help") == 0)
		{
			char line[255];
			FILE *file = fopen("help.txt", "r");

			if (file == NULL)
			{
				printf("Ошибка!!!\nФайла со справкой нет в директоркии!!!\n");
				return 0;
			}
			while(fgets(line, 255, file) != NULL)
			{
			printf("%s", line);
			}

			fclose(file);

			return 0;
		}
	}

	//Проверка на кол-во аргументов
	if (argc > 6){
		printf("Слишком много аргументов.\n\nДля справки перезапустите с флагом --help\n");
		return 0;
	}
	if ((argc < 5) && (argc == 1))
	{
		printf("Слишком мало аргументов.\n\nДля справки перезапустите с флагом --help\n");
		return 0;
	}

	time_t timer1 = time(NULL);  //Начальный таймер 
	/*--------------------------------------------------*/


	FILE *file = fopen(argv[1], "r");//Открываем файл
	char line[255];
	while (fgest(line, 255, file) != NULL)
	{
		printf("%s", line);
	}



	fclose(file); //Закрываем файл

	/*--------------------------------------------------*/
	time_t timer2 = time(NULL); //Конечный таймер

	printf("%f\n", difftime(timer2, timer1));



	return 0;
}