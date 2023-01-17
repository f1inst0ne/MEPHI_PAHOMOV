#include<stdio.h>
#include<stdlib.h>


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

			len += mylen(buf);
			ptr = (char *) realloc(ptr, len + 1);
			mycat(&ptr, buf);

		}
	}  while(n > 0);
	
	return ptr;
}


//strlen
int mylen(char *str)
{ 
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}


//strcat
void mycat(char **dest, char *src){
	int index = mylen((*dest));
	int i = 0;
	(*dest) = (char*)realloc((*dest), sizeof((*dest)) + sizeof(src) + 1);
	while (src[i] != '\0'){
		(*dest)[index] = src[i];
		index++;
		i++;
	}
	(*dest)[index] = '\0'; 
}


//ctrcpy
void mycpy(char **dest, char *src)
{
	int src_len = mylen(src);
	free(*dest);
	(*dest) = (char*)calloc(src_len+1, sizeof(char));

	int i = 0;
	while(src[i] != '\0')
	{
		(*dest)[i] = src[i];
		i++;
	}
}