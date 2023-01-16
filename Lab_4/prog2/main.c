#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"task.h"
#include"lib.h"

int main(){
	char *string;
	while (1){
		string = input();
		if (string == NULL){
			free(string);
			break;
		}
		task(string);
		free(string);
	}
	return 0;
}
