#include<stdio.h>
#include<math.h>

int fact(int);
int step(double, int);


int main(){
	double x = 0;
	int n = 0;
	double ans = 1;
	int f = 0;
	double s = 0;
	printf("Enter x:");
	scanf("%lf", &x);
	printf("Enter n:");
	scanf("%d", &n);
	for (int i; i < n+1; i += 1){
		s = step(-x, n);
		f = fact(n);
		ans += s/f;
	}
	printf("Your answer:%lf \n", 1/ans);
	printf("True answer:%lf", exp(-(x*x)));
	return 0;
}


int fact(int n){
	if (n == 0){
		return 1;
	}
	else{
		int f = 1;
		for (int i = 1; i < n+1; i += 1){
			f *= i;
		}
	}
}

int step(double x, int n){
	double s = 1;
	double r = x*x;
	for (int i = 0; i < n; i += 1){
		s *= r;		
	}
	return s;
	
}	


