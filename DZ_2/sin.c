#include<stdio.h>
#include<math.h>


long double new_sin(long double, long double);
long double m(long double);


int main(){
	long double x = 0;
	long double n = 0;
	long double pi = 3.14159265359;
	printf("Введите угол(x):");
	scanf("%Lf", &x);
	printf("Введите точность(n):");
	scanf("%Lf", &n);
	long double n_sin = new_sin(x, n);
	long double t_sin = sin(x);
	printf("\n---------------------------------\nВаш синус: %.10Lf\nПравильный синус: %.10Lf\n", n_sin, t_sin);	
	
	return 0;
}


long double new_sin(long double x, long double n){
	long double s = 0;
	long double p = x;
	int z = 1;
	printf("\n-----s = %.10Lf, p = %.10Lf, z = %d\n", s, p, z);
	while (m(p) > n){
		s += p;
		p *= -1 * x*x / (z+1)/(z + 2);
		z += 2;
		
		printf("-----s = %.10Lf, p = %.10Lf, z = %d\n", s, p, z);

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
