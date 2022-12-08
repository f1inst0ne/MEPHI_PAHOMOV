#include<stdio.h>
#include<stdlib.h>
#include"arraylib.h"
#include"task.h"

int menu_check();

int main(){
	system("clear");
	int len = 0;
	int *array = malloc(sizeof(int));
	while (1){
		system("clear");
		printf("\nВыберете действие:\n1)Инициализировать новый массив и заполнить его\n2)Добавить элемент в конец\n3)Добавить элемент по индексу\n4)Удалить элемент по индексу\n5)Обработать массив по индивидуальному заданию\n6)Выход\n\nСостояние массива на данный момент:\n");
		print_array(len, array);
		printf("-----------------------------\n");
		/* -----------------------------*/
		int user_input = menu_check();
		if (user_input == 1){
			free(array);
			printf("Введите длину нового массива:");
			scanf("%d", &len);
			array = init_array(len);
		}
		if (user_input == 2){
			len += 1;
			array = realloc(array, len*sizeof(int));
			array = add_to_end(array, len);
		}
		if (user_input == 3){
			add_by_index(&array, &len);
		}
		if (user_input == 4){
			int index = 0;
			printf("Введите индекс:");
			scanf("%d", &index);
			del_by_index(&array, &len, index);
		}
		if (user_input == 5){
			task(array, len);
		}
		if (user_input == 6){
			free(array);
			return 0;
		}
		if ((user_input >= 7) || (user_input <= 0)){
			system("clear");
			printf("Неизвестная команда!!!!! Попробуйте снова!!!\n\nВведите любое число для проболжения...\n");
			int exit_input = 0;
			scanf("%d", &exit_input);
		}
	}
}

int menu_check(){
	int user_input;
	printf("Что вы хотите сделать?\n>");
	scanf("%d", &user_input);
	return user_input;
}


