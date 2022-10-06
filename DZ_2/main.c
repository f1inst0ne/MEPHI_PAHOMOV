#include<stdio.h>
#include<math.h>


int step(int n, double x){
	double s = x;
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





int main(){
	int n = 0;
	double x = 0;
	double ans = 0;
	scanf("%d", &n);
	scanf("%lf", &x);
	int f = fact(n);
	double s = step(n, x);
	for (int i = n; i != 1; i -= 1){
		ans += (s/f);
		s /= n;
		f /= x;

	}
	print("True answer:%.3lf", math.exp())
	printf("Your nubmer:%.3lf \n", ans);
	return 0;
}
