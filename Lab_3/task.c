#include<stdio.h>
#include<stdlib.h>

int task(){
	return 5555;
}

void write_task(){
	system("clear");
	int exit_input;
	printf("Индивидуальное задание\nВ исходной последовательности целых чисел найти те, которые состоят из одинаковых цифр. Сформировать из данных чисел новую последовательность, удалив их из исходной.\n\nВведите любое число, чтобы продолжить...\n");
	scanf("%d", &exit_input);

}
