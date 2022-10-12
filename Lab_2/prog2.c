/*Лабораторную работу выполнил Пахомов Андреей Б22-554*/
#include<stdio.h>
#include<math.h>

long double func(long double);
long double m(long double);

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
	long double p = 1;
	int s = -1;
	long double i = 1;
	printf("$ p = %.10Lf, s = %d, i = %Lf\n");
	while (m(p)>n){
		p = p * (1+(s/(2*i + 1)));
		s = -s;
		i += 1;
		printf("$ p = %.10Lf, s = %d, i = %Lf\n");
	}
	return p;
}
long double m(long double x){
	if (x >= 0){
		return x;
	}
	else{
		return -x;
	}
}


