#include<stdio.h>
#include<stdlib.h>


/*Инициализация массива. Создает массив длиной len. */
int *init_array(int len){
	int* new_array = malloc(len * sizeof(int));
	return new_array;
}

int *fill_array(int len, int *array){
	int a = 0;
	printf("Введите значения, по одному в строке:\n");
	for (int i = 0; i < len; i ++){
		printf(">");
		scanf("%d", &a);
		array[i] = a;

	}
	return array;
}

void print_array(int len, int *array){
	printf("\nДлина массива на данный момент:%d\n[", len);
	for (int i = 0; i < len; i++){
		if (i == len - 1){
		printf("%d", array[i]);
		}
		else{
		printf("%d, ", array[i]);
		}
	}
	printf("]\n");
}

/* ДОДЕЛАТЬ */
int *add_by_index(int *array, int len ){
	int new = 0;
	int index = 0;
	int *new_array = malloc(len*sizeof(int));
	printf("Введите новый элемент:\n>");
	scanf("%d", &new);
	printf("Введите индекс, куда поставить:");
	scanf("%d", &index);
	if (index >= len){
		index = len-1;
	}
	for (int i = 0; i < len; i++){
		if (i == index){
		new_array[i] = new;
		}
		else{
		new_array[i] = array[i];
		}
	}
	return new_array;

}

/* ДОДЕЛАТЬ */
int del_by_index(){
	return 4444;
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
