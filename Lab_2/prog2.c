/*Лабораторную работу выполнил Пахомов Андреей Б22-554*/
#include<stdio.h>
#include<math.h>

long double func(long double);
long double m(long double);
long double check(long double);


int main(){
	long double n = 0;
	printf("Введите точность:");
	scanf("%Lf", &n);
	if (n <= 0){
		printf("Ошибка!!!!!! Введено не подходящее значение...");
		return 1;
	}
	long double ans = func(n);
	long double t_ans = sqrt(2)/2;
	printf("--------------------\nМой ответ:%.10Lf\nПравильный ответ:%.10Lf\n\n\n", ans, t_ans);
	return 0;
}

long double func(long double n){
	long double p = 1;
	int s = -1;
	long double i = 1;
	while (1+(s/(2*i + 1))>n){
		if ((p * (1+(s/(2*i + 1)))- p) < n && (p * (1+(s/(2*i + 1)))- p) > 0){	
			break;
		}
		else{
			p = p * (1+(s/(2*i + 1)));
			s = -s;
			i += 1;
		}
	}
	return p;
}
