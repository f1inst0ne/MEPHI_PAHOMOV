#include<stdio.h>

int reverse(int n){
	int p = 0;
	int s = 1;

	while (s < n){
		s *= 10;
	}
	s /= 10;
	while (n > 0){
		p += (n%10)*s;
		n /= 10;
		s /= 10;
	}
	return p;
}


int check(int n, int p){
	int c = n % 10;
	int d = 0;
	while (p > 0){
		if (p%10 == c){
			d = 1;
			return d;	
		}
		else{
			p /= 10;
		}
	}
	return d;
}

int gen(int n){
	int i = 1; /* Снова число, на которое умножаем, чтобы поставить цифру в нужный разряд */
	int nul = 0; /* Переменная, которая показывает, есть ли в новом числе ноль или нет */
	int p = 0; /* Новое число */
	int d = 0; /* Переменная флаг, которая используется далее, для того чтобы понять, повторилась ли цифра */
	while (n > 0){
		d = check(n, p);
		if (d == 1){
			n /= 10;
		}
		else{
			if (n%10 == 0){		/* Проверяем, является ли новая цифра нулем */
				if (nul == 0){	/* Проверяем наличие нулей в новом числе */
					nul += 1;
					i *= 10;
					n /= 10;
				}
				else{
					n /= 10;
				}
			}
			else{
				p += (n%10)*i;
				i *= 10;
				n /= 10;
			}
		}
	}
	return p;
}



int main(){
	int n = 0;
	printf("Enter the number:");
	scanf("%d", &n);
	n = reverse(n);
	int p = gen(n);
	printf("%d \n", reverse(p));

	return 0;
}	




