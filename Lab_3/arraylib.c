#include<stdio.h>
#include<stdlib.h>


/*Инициализация массива. Создает массив длиной len. */
int *init_array(int len){
	int* new_array = malloc(len * sizeof(int));
	return new_array;
}

int *fill_array(int len, int *array){
	int a = 0;
	for (int i = 0; i < len; i ++){
		printf(">");
		scanf("%d", &a);
		array[i] = a;

	}
	return array;
}

void print_array(int len, int *array){
	for (int i = 0; i < len; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}


/*Недоработанная функция */
/*
int *refill_array(int *array){
	int len = sizeof(array)/sizeof(int), a;
	printf("%d", len);
	for (int i = 0; i < len; i ++){
		printf(">");
		scanf("%d", &a);
		array[i] = a;
	}
	return array;
}*/
