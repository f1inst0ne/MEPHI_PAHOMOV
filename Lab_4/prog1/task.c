#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void task(char *str){
	if ((str[0] == ' ') || (str[strlen(str)-1] == ' ')){
		printf("Ошибка!!!\nВведена строка оканчивающаяся на пробел или начинающаяся с него...\n");
		return;
	}
	
	char last_letter = str[strlen(str)-1];
	char sep[]=" ";
	char *word;
	char *result = (char*)malloc(81*sizeof(char));
	word = strtok(str, sep);
	int word_len = strlen(word);
	int result_len = 0;
	while (word != NULL){
		if (word[0] == last_letter){
			result = (char*)realloc(result, (word_len + result_len +1)* sizeof(char));
			strcat(result, word);
			strcat(result , " ");
		}
		word  = strtok(NULL, sep);
		word_len = strlen(word);
		result_len = strlen(result) + word_len + 1;
	}
	printf("%s\n", result);
}
