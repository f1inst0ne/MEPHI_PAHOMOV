#include<stdio.h>
#include<stdlib.h>
#include"arraylib.h"


int main(){
	int *array;
	int len = 0;
	printf("Введите длину массива:");
	scanf("%d", &len);
	array = init_array(len);
	
	printf("[");
	for (int i = 0; i < len; i++){
		printf("%d ", array[i]);
	}
	printf("]\n");

	
	for (int i = 0; i < len-1; i++){
		for (int j = i+1; j < len; j++){
			if (array[i] == array[j]){
				del_by_index(&array, &len, j);
			}
		}
	}
	
	printf("[");
	for (int i = 0; i < len; i++){
		printf("%d ", array[i]);
	}
	printf("]\n");


	free(array);
	return 0;
}
