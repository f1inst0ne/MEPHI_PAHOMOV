#include<stdio.h>
#include<math.h>

long double new_sin(long double, int);
long double step(long double, int);
int fact(int);
int minus(int);


int main(){
	long double x = 0;
	int n = 0;
	printf("Enter x:");
	scanf("%Lf", &x);
	printf("Enter n:");
	scanf("%d", &n);
	while (x > 360){
		x -= 360;
	}
	long double t_sin = sinl(x);
	long double n_sin = new_sin(x, n);
	printf("\nTrue sin:%.10Lf\n", t_sin);
	printf("Your sin:%.10Lf\n", n_sin);
	return 0;
}


/* --------------------------------------------- */
long double new_sin(long double x, int n){
	long double s = 0;
	long double chis = minus(n-1) * step(x, 2*n - 1);
	int znam = fact(2*n - 1);
	printf("----- s = %Lf, chis = %Lf, znam = %d, x = %Lf, n = %d\n", s, chis, znam, x, n);
	while (n > 0){
		s += chis / znam;
		chis = chis / (x * x);
		znam = znam / (n*(n-1));
		n -= 2;
	        printf("----- s = %Lf, chis = %Lf, znam = %d, x = %Lf, n = %d\n", s, chis, znam, x, n);

	}
	return s;
}


long double step(long double x, int n){
	long double s = 1;
	for (int i = 1; i < n+1; i++){
		s *= x;
	}
	return s;
}


int fact(int n){
	int f = 1;
	for (int i = 1; i < n+1; i++){
		f *= i;
	}
	return f;
}


int minus(int n){
	int m = 1;
	for (int i = 1; i < n+1; i++){
		m *= -1;
	}
	return m;
}
