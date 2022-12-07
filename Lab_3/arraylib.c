#include<stdio.h>
#include<stdlib.h>


/*Инициализация массива. Создает массив длиной len. */
int *init_array(int len){
	int* new_array = malloc(len * sizeof(int));
	int a = 0;
	printf("Введите значения, по одному в строке:\n");
	for (int i = 0; i < len; i ++){
		printf(">");
		scanf("%d", &a);
		new_array[i] = a;

	}
	return new_array;
}



int *copy_array(int *array, int len){
	int *new_array = malloc(len*sizeof(int));
	for (int i = 0; i < len; i++){
		new_array[i] = array[i];
	}
	return new_array;
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
int *add_to_end(int *array, int len){
	int new = 0;
	printf("Введите новый элемент:\n>");
	scanf("%d", &new);
	array[len-1] = new;
	return array;
}
int *add_to_end_known(int *array, int len, int new){
	array[len-1] = new;
	return array;
}


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
	for (int i = len; i > index; i = i - 1){
		new_array[i] = array[i-1];
	}
	for (int i = 0; i < index; i++){
		new_array[i] = array[i];
	}
	new_array[index] = new;
	return new_array;

}

int *del_by_index(int *array, int len){
	int index = 0;
	printf("Введите индекс:\n>");
	scanf("%d", &index);
	int *new_array = malloc(len*sizeof(int));
	for (int i = 0; i < index; i++){
		new_array[i] = array[i];
	}
	for (int i = index; i < len; ++i){
		new_array[i] = array[i+1];
	}
	return new_array;
}

int *del_by_known_index(int *array, int len, int index){
	int *new_array = malloc(len*sizeof(int));
	for (int i = 0; i < index; i++){
		new_array[i] = array[i];
	}
	for (int i = index; i < len; ++i){
		new_array[i] = array[i+1];
	}
	return new_array;
}

