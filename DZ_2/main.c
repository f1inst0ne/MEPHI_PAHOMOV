#include<stdio.h>
#include<math.h>
int my_exp(long double, int);

int main (){
	long double x = 0;
	int n = 0;
	printf("Enter X:");
	scanf("%Lf", &x);
	printf("Enter n:");
	scanf("%d", &n);
	double ans = my_exp(x, n);
	printf("%.10Lf\n", ans);
	printf("%.10Lf\n", exp(-1*x*x));
	return 0;
}

int my_exp(long double x, int n){
	long double p = 1;
	long double s = 1;
	for (int i = 1; i <= n; ++i){
		p  = -p*x*x/i;
		s += p;
	}
	return s;
	
}
