#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<readline/readline.h>
#include"task.h"

int main(){
	system("clear");
	char *string;
	printf("Вводите строки и получайте результат.\nДля прекращения программы нажмите сочетание клавиш CTRL+d\n");
	while(1){
		string = readline(">>>");
		if (string == NULL){
			printf("\nЗавершаю...\n");
			break;
		}
		
		task(string);
		
		free(string);
	}
	return 0;
} 

