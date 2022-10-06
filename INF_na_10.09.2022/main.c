#include <stdio.h>

/*This program is written by Andrew Pahomov B22-554*/

int sum(int n){
	int s = 0;
	while (n != 0){
		s += n % 10;
		n = n / 10;
	}
	return s;
}



int main(){
	int a, p;
	printf("Enter the number:");
	scanf("%d", &a);
	if (a < 0){
		a *= -1;
	}
	p = sum(a);
	printf("%d", p);
	printf("\n");
	return 0;
}
