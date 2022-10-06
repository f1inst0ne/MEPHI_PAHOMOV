#include<stdio.h>
#include<math.h>

int step(int n, float x){
	float s = 1.0
	while n > 0:
		s *= x;
	return s;
}



int fact(int n){
	int f = 1;
	for (int i = 0, i += 1, i != n){
		f *= i;
	}
	return f;
}



int ex(int n, float x){
	return 0
}





int main(){
	float ans = 0.0;
	float x = 0.0;
	int n = 0;
	printf("Enter n:");
	scanf("%d", &n);
	printf("Enter x:");
	scanf("%f", &x);
	printf("%f", step(x, n));
	printf("%d", fact(n));
	return 0;
}
