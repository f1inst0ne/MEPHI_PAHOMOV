#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void task(char *string){
	if ((string[0] == ' ') || (string[strlen(string)-1] == ' ')){
		printf("Ошибка!!!\nВведена строка оканчивающаяся на пробел или начинающаяся с него...\n");
		return;
	}
	char *str = (char*)calloc(128, sizeof(char));
	strcpy(str, string);
	char last_letter = str[strlen(str)-1];
	char *word;
	char *result = (char*)calloc(128, sizeof(char));
	char *istr = (char*)malloc(128*sizeof(char));
	word = strtok(str, " ");
	while (word != NULL){
		strcpy(istr, word);
		if (istr[0] == last_letter){
			strcat(result, istr);
			strcat(result, " ");
		}
		word  = strtok(NULL, " ");
	}
	free(str);
	str = (char*)calloc(128, sizeof(char));
	strcpy(str,string);
	word = strtok(str, " ");
	while (word != NULL){
		strcpy(istr, word);
		if (istr[0] != last_letter){
			strcat(result, istr);
			strcat(result, " ");
		}
		word  = strtok(NULL, " ");
	}
	printf("%s\n", result);
	free(str);
	free(result);
	free(istr);
}
