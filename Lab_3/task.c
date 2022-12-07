#include<stdio.h>
#include<stdlib.h>
#include"arraylib.h"

int schet(int);
int check(int, int);


void task(int *array, int len){
	system("clear");
	int *new_array = malloc(sizeof(int));
	int new_len = 0;
	for (int i = 0; i < len; i++){
		int found = 0;
		for (int j = i+1; j < len; j++){
			if (check(array[i], array[j])){
				found = 1;
				new_len += 1;
				new_array = realloc(new_array, new_len*sizeof(int));
				new_array[new_len-1] = array[j];
				array = del_by_known_index(array, len, j);
				len -= 1;
				array = realloc(array, len * sizeof(int));
			}
		}
		if (found){
			new_len += 1;
			new_array = realloc(new_array, len*sizeof(int));
			new_array[new_len-1] = array[i];
			array = del_by_known_index(array, len, i);
			len -= 1;
			array = realloc(array, len * sizeof(int));
			}

		}


	
	
	
	
	
	print_array(new_len, new_array);
	print_array(len, array);
	int exit_input = 0;
	printf("Введите любое число, чтобы продолжить...\n");
	scanf("%d", &exit_input);
}

void write_task(){
	system("clear");
	int exit_input;
	printf("Индивидуальное задание\nВ исходной последовательности целых чисел найти те, которые состоят из одинаковых цифр. Сформировать из данных чисел новую последовательность, удалив их из исходной.\n\nВведите любое число, чтобы продолжить...\n");
	scanf("%d", &exit_input);

}

int check(int num1, int num2){
	int result = 1;
	int *num1_array, *num2_array;
	int len1 = schet(num1), len2 = schet(num2);
	num1_array = malloc(len1 * sizeof(int));
	num2_array = malloc(len2 * sizeof(int));
	/* заполняем массивы цифрами */
	for (int i = 0; i < len1; i++){
		num1_array[i] = num1%10;
		num1 /= 10;
	} 	
	for (int i = 0; i < len2; i++){
		num2_array[i] = num2%10;
		num2 /= 10;
	}
	/* Сортируем */
	
	for (int i = 0; i < len1; i++){
		for (int j = 0; j < len1-1; j++){
			if (num1_array[j] > num1_array[j+1]){
				int buf = num1_array[j];
				num1_array[j] = num1_array[j+1];
				num1_array[j+1] = buf;
			}
		}
		
	}
		
	for (int i = 0; i < len2; i++){
		for (int j = 0; j < len2-1; j++){
			if (num2_array[j] > num2_array[j+1]){
				int buf = num2_array[j];
				num2_array[j] = num2_array[j+1];
				num2_array[j+1] = buf;
			}
		}
		
	}
	
	
	/* Сравниваем */
	if (len1 != len2){
		result = 0;
	}
	else{
		for (int i = 0; i < len1; i ++){
			if (num1_array[i] != num2_array[i]){
				result = 0;
				break;
			}
		}
	}
	free(num1_array);
	free(num2_array);
	return result;
}


int schet(int n){
	int len = 0;
	while (n > 0){
		len += 1;
		n /= 10;
	}
	return len;
}

