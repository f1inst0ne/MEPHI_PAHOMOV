#include<stdio.h>
#include<math.h>

long double new_exp(long double, int);


int main(){
	long double x = 0;
	int n = 0;
	printf("Enter x:");
	scanf("%Lf", &x);
	printf("Enter n:");
	scanf("%d", &n);
	printf("So you have: x=%Lf n=%d \n", x, n);
	long double m_exp = new_exp(x, n);
	long double t_exp = exp(-1*x*x);
	printf("\nTrue exp: %.10Lf \n", t_exp);
	printf("Your exp: %.10Lf \n", m_exp);
	return 0;
}

long double new_exp(long double x, int n){
	long double e = 1;
	long double p = 1;
	for (int i = 1; i < n+1; ++i){
		p = p * (-1) * x * x / i;
		e += p;
		/*printf("------- e = %Lf, p = %Lf, i  = %d\n", e, p, i);*/
	}
	return e;
}	
