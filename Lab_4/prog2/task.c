#include<stdio.h>
#include<stdlib.h> 
#include"lib.h"

char *make_word(char *, int, int);

void task(char *str){
	//Проверка на корректность ввода 
	if ((str[0] == ' ') || (str[mylen(str)-1] == ' '))
	{
		printf("Ошибка!!!\nВведена строка оканчивающаяся на пробел или начинающаяся с него...\n");
		return;
	}

	char *result = (char*)calloc(1, sizeof(char));
	char last_letter = str[mylen(str)-1];
	//Создаем и наполняем массив индексов, для того, что бы потом слова составлять

	int *index = (int*)calloc(1, sizeof(int));
	int index_len = 0, i = 0;
	index_len++;
	index = (int*)realloc(index, index_len*sizeof(int));
	index[index_len-1] = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			index_len++;
			index = (int*)realloc(index, index_len*sizeof(int));
			index[index_len-1] = i;
		}
		i++;

	}

	index_len++;
	index = (int*)realloc(index, index_len*sizeof(int));
	index[index_len-1] = mylen(str);

	//Генерируем слова и обрабатываем
	for (int j = 0; j < index_len-1; j++)
	{
		int start_index = index[j], end_index = index[j+1];
		char *word = make_word(str, start_index, end_index);
		if (word[0] == last_letter){	
			mycat(&result, word);
			mycat(&result, " ");
		}
		free(word);
	}
	for (int j = 0; j < index_len-1; j++)
	{
		int start_index = index[j], end_index = index[j+1];
		char *word = make_word(str, start_index, end_index);
		if (word[0] != last_letter){	
			mycat(&result, word);
			mycat(&result, " ");
		}
		free(word);
	}
	printf("%s\n", result);
	free(index);
	free(result);
}



char *make_word(char *str, int start, int stop)
{
	char *word = (char*)calloc(1, sizeof(char));
	int word_len = 0;
	if (start != 0)
	{
		start++;
	}
	for (int i = start; i < stop; i++)
	{
		word_len++;
		word = (char*)realloc(word, word_len*sizeof(char));
		word[word_len-1] = str[i];
	}
	word_len++;
	word = (char*)realloc(word, word_len*sizeof(char));
	word[word_len-1] = '\0';
	
	return word;
}