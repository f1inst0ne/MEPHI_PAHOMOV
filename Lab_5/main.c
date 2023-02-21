#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include"lib.h"


int main(int argc, char *argv[])
{	
	//Проверка корректности ввода
	
	
	if ((argc == 1) || ((argc != 11) && !(strcmp(argv[1], "-h") == 0)))
	{
		printf("--------------------------\nError!!!\nFor help restart with\n\n./test -h\n--------------------------\n");
		return 0;
	}


	//Обрабатывем аргументы командной строки
	int arg = 0;
	char *alg;
	char *pole;
	char *nap;
	char *input_name;
	char *output_name;

	while ((arg = getopt(argc, argv, "ha:p:n:f:o:")) != -1)
	{
		switch(arg)
		{
			case 'h':
				print_help();
				return 0;
			case 'a': 
				alg = (char*)calloc(strlen(optarg)+1, sizeof(char));
				strcpy(alg, optarg);
				break;
			case 'p':
				pole = (char*)calloc(strlen(optarg)+1, sizeof(char));
				strcpy(pole, optarg);
				break;
			case 'n':
				nap = (char*)calloc(strlen(optarg)+1, sizeof(char));
				strcpy(nap, optarg);
				break;
			case 'f':
				input_name = (char*)calloc(strlen(optarg)+1, sizeof(char)); 
				strcpy(input_name, optarg);
				break;
			case 'o':
				output_name = (char*)calloc(strlen(optarg)+1, sizeof(char)); 
				strcpy(output_name, optarg);
				break;
			case '?': printf("--------------------------\nError!!!\nFor help restart with\n\n./test -h\n--------------------------\n"); return 0;
		}
	}


	if (flags_check(alg, pole, nap) == 0)
	{
		printf("--------------------------\nError!!!\nFor help restart with\n\n./test -h\n--------------------------\n"); 
		return 0;

	}


	
	//Открывем входной файл
	FILE *input = fopen(input_name, "r");

	if (!input)
	{
		printf("--------------------------\nError!!!\nФайла на вход НЕ СУЩЕСТВУЕТ!!!\n\n--------------------------\n");
		return 0;
	}
	

	//Создаем массив структур
	int len = 0;
	node *array = (node*)calloc(1, sizeof(node));

	char line[255];
	char *word;
	while(fgets(line, 255, input) != NULL)
	{
		len++;
		array = (node*)realloc(array, len*sizeof(node));

		word = strtok(line, ",");
		(array[len-1]).name = (char*)malloc((strlen(word) + 1) * sizeof(char));
		memcpy((array[len-1]).name, word, (strlen(word) + 1) * sizeof(char));
		
		word = strtok(NULL, ",");
		/*strcpy((array[len-1]).num, word);*/
		//(array[len-1]).num = (char*)malloc((strlen(word) + 1) * sizeof(char));
		memcpy((array[len-1]).num, word, (strlen(word) + 1) * sizeof(char));
		

		word = strtok(NULL, ",");
		(array[len-1]).age = atoi(word);


	}

	clock_t start, end;
	start = clock();

	if (strcmp(alg, "odd") == 0)
	{
		odd_even_sort(array, len, pole, nap, output_name);

	}
	else if(strcmp(alg, "selection") == 0)
	{
		selection_sort(array, len, pole, nap, output_name);

	}
	else if(strcmp(alg, "quick") == 0)
	{
		quick_sort(array, len, pole, nap, output_name);

	}
	else
	{
		printf("Произошла неведомая херня. Не знаю как я запустилась, но ошибка есть!!!\n");
	}
	end = clock();

	double total = (double) (end-start) / CLOCKS_PER_SEC;

	printf("Time: %fs\n", total);




	//Отчистка памяти,дабы всеми любимый валгринд не ныл

	for (int i = 0; i < len; i++)
	{
		free((array[i]).name);
		//free((array[i]).num);
	}

	free(array);
	fclose(input);
	free(alg); 
	free(pole); 
	free(nap); 
	free(input_name); 
	free(output_name);
	return 0;
}