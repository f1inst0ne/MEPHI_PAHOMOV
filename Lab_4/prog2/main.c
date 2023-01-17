#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"task.h"
#include"lib.h"

int main(){
	system("clear");
	char *string;
	printf("Вводите строки и получайте результат.\nДля прекращения программы нажмите сочетание клавиш CTRL+d\n");
	while (1){
		printf(">>>");
		string = input();
		if (string == NULL){
			free(string);
			printf("\nЗавершаю...\n");
			break;
		}
		task(string);
		free(string);
	}
	return 0;
}
