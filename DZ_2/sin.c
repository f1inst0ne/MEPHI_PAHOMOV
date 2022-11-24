#include<stdio.h>
#include<math.h>


long double new_sin(long double, long double);
long double m(long double);
long double check(long double);

int main(){
	long double x = 0;
	long double n = 0;
	printf("Введите угол(x):");
	scanf("%Lf", &x);
	printf("Введите точность(n):");
	scanf("%Lf", &n);
	long double n_sin = new_sin(check(x), n);
	long double t_sin = sin(x);
	printf("\nМоя функция:%Lf\nБиблиотечная фун-я:%Lf\n\n", n_sin, t_sin);
	return 0;
}


long double new_sin(long double x, long double n){
	long double s = 0;
	long double p = x;
	int z = 1;
	while (m(p) > n){
		s += p;
		p *= -1 * x*x / (z+1)/(z + 2);
		z += 2;
	}
	return s;
}

long double m(long double x){
	if (x >= 0){
		return x;
	}
	else{
		return -x;
	}
}

long double check(long double x){
	if (x >= 0){
		while (x >= 2 * M_PI){
			x -= 2 * M_PI;
		}
	}
	else{
		while (x < -2 * M_PI){
			 x += 2 * M_PI;
		}
	}
	return x;
}
