#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char *input()
{
	char *ptr = (char *)malloc(1);
	char buf[81];
	int n, len = 0;
	*ptr = '\0';
	do{
		n = scanf("%80[^\n]", buf); // n = scanf_s ("%80[^\n]", buf, 81);
		if(n < 0){
		free(ptr);
		ptr = NULL;
		continue;

		}
		if(n == 0)

		scanf("%*c");

		else {

		len += strlen(buf);
		ptr = (char *) realloc(ptr, len + 1);
		strcat(ptr, buf);

		}
	}  while(n > 0);
	return ptr;
}
