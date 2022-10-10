#include<stdio.h>
#include<math.h>

long double func(int);


int main(){
	long double x = sqrt(2)/2;
	int n = 0;/*Кол-во членов*/
	printf("Введите кол-во членов:");
	scanf("%d", &n);
	long double ans = func(n);
	printf("Мой ответ:%.10Lf\n", ans);
	printf("Правильный ответ:%.10Lf", x);
	return 0;
}

long double func(int n){
	long double p = 1;
	int s = -1;
	printf("$ p = %.10Lf, s = %d, i = %d\n", p, s, 0);
	for (int i = 1; i < n+1; i++){
		p *= 1+(s/(2*i + 1));
		s = -s;
		printf("$ p = %.10Lf, s = %d, i = %d\n", p, s, i);

	}
	return p;

}
