#include<stdio.h>
#include<stdlib.h>
#include"arraylib.h"



int main(){
	system("clear");
	int len  = 0;
	printf("Enter len:");
	scanf("%d", &len);
	int *a = init_array(len);
	a = fill_array(len, a);
	print_array(len, a);
	free(a);
	return 0;
}




