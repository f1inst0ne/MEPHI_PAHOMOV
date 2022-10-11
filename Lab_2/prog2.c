/*Лабораторную работу выполнил Пахомов Андреей Б22-554*/
#include<stdio.h>
#include<math.h>

long double func(long double);


int main(){
	long double n = 0;
	printf("\n\nВведите точность:");
	scanf("%Lf", &n);
	long double ans = func(n);
	long double t_ans = sqrt(2)/2;
	printf("--------------------\nМой ответ:%.10Lf\nПравильный ответ:%.10Lf\n\n\n", ans, t_ans);
	return 0;
}

long double func(long double n){
	return 1231231;
}
