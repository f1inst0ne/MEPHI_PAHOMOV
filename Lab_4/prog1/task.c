#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void task(char *str){
	printf("%s\n", strtok(str, " -,."));
}
