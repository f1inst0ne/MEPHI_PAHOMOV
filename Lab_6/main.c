#include<stdio.h>
#include<stdlib.h>
#include"lib.h"

int main()
{	
	List *list = init_list();
	printf(">>>");
	fill_list(&list);
	task(&list);
	print_list(list);
	free_list(&list);
	free(list);
	return 0;
}
