#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lib.h"

void print_help()
{
	FILE *file = fopen("help.txt", "r");

	if (file == NULL)
	{
		printf("There is no \"help.txt\" file in directory!!!");
		return;
	}

	char line[255];
	while (fgets(line, 255, file) != NULL)
	{
		printf("%s", line);
	}

	fclose(file);

}



int flags_check(char *alg, char *pole, char *nap)
{
	int flag = 1;

	if ((strcmp(alg, "odd") != 0) && (strcmp(alg, "selection") != 0) && (strcmp(alg, "quick") !=0 ))
	{
		flag = 0;
	} 
	if ((strcmp(pole, "1") != 0) && (strcmp(pole, "2") != 0) && (strcmp(pole, "3") != 0))
	{
		flag = 0;
	} 
	if ((strcmp(nap, "up") != 0) && (strcmp(nap, "down") != 0))
	{
		flag = 0;
	} 


	return flag;
}






void odd_even_sort(node *array, int len, char *pole, char *nap, char *output_name)
{
	FILE *file = fopen(output_name, "w");

	if (strcmp(nap, "up") == 0)
	{
		if (strcmp(pole, "1") == 0)
		{
			int sorted = 0;
			node buf;

			while(!sorted)
			{
				sorted = 1;

				for (int i = 1; i <= len - 2; i = i + 2) 
				{
					if ((strcmp((array[i]).name, (array[i+1]).name) > 0) || (strcmp((array[i+1]).name, (array[i]).name) < 0))
					{
						buf = array[i];
						array[i] = array[i+1];
						array[i+1] = buf;
						sorted = 0;
					}
				}

				for (int i = 0; i <= len - 2; i = i + 2) 
				{
					if ((strcmp((array[i]).name, (array[i+1]).name) > 0) || (strcmp((array[i+1]).name, (array[i]).name) < 0))
					{
						buf = array[i];
						array[i] = array[i+1];
						array[i+1] = buf;
						sorted = 0;
					}
				}
			}
		}
	
		else if (strcmp(pole, "2") == 0)
		{
			int sorted = 0;
			node buf;

			while(!sorted)
			{
				sorted = 1;

				for (int i = 1; i <= len - 2; i = i + 2) 
				{
					if ((strcmp((array[i]).num, (array[i+1]).num) > 0) || (strcmp((array[i+1]).num, (array[i]).num) < 0))
					{
						buf = array[i];
						array[i] = array[i+1];
						array[i+1] = buf;
						sorted = 0;
					}
				}

				for (int i = 0; i <= len - 2; i = i + 2) 
				{
					if ((strcmp((array[i]).num, (array[i+1]).num) > 0) || (strcmp((array[i+1]).num, (array[i]).num) < 0))
					{
						buf = array[i];
						array[i] = array[i+1];
						array[i+1] = buf;
						sorted = 0;
					}
				}
			}
		}
		else if (strcmp(pole, "3") == 0)
		{
			int sorted = 0;
			node buf;

			while(!sorted)
			{
				sorted = 1;

				for (int i = 1; i <= len - 2; i = i + 2) 
				{
					if ((array[i]).age > (array[i + 1]).age)
					{
						buf = array[i];
						array[i] = array[i+1];
						array[i+1] = buf;
						sorted = 0;
					}
				}

				for (int i = 0; i <= len - 2; i = i + 2) 
				{
					if ((array[i]).age > (array[i + 1]).age)
					{
						buf = array[i];
						array[i] = array[i+1];
						array[i+1] = buf;
						sorted = 0;
					}
				}
			}
		}
 	}


 	if (strcmp(nap, "down") == 0)
	{
		if (strcmp(pole, "1") == 0)
		{
			int sorted = 0;
			node buf;

			while(!sorted)
			{
				sorted = 1;

				for (int i = 1; i <= len - 2; i = i + 2) 
				{
					if ((strcmp((array[i]).name, (array[i+1]).name) < 0) || (strcmp((array[i+1]).name, (array[i]).name) > 0))
					{
						buf = array[i];
						array[i] = array[i+1];
						array[i+1] = buf;
						sorted = 0;
					}
				}

				for (int i = 0; i <= len - 2; i = i + 2) 
				{
					if ((strcmp((array[i]).name, (array[i+1]).name) < 0) || (strcmp((array[i+1]).name, (array[i]).name) > 0))
					{
						buf = array[i];
						array[i] = array[i+1];
						array[i+1] = buf;
						sorted = 0;
					}
				}
			}
		}
	
		else if (strcmp(pole, "2") == 0)
		{
			int sorted = 0;
			node buf;

			while(!sorted)
			{
				sorted = 1;

				for (int i = 1; i <= len - 2; i = i + 2) 
				{
					if ((strcmp((array[i]).num, (array[i+1]).num) < 0) || (strcmp((array[i+1]).num, (array[i]).num) > 0))
					{
						buf = array[i];
						array[i] = array[i+1];
						array[i+1] = buf;
						sorted = 0;
					}
				}

				for (int i = 0; i <= len - 2; i = i + 2) 
				{
					if ((strcmp((array[i]).num, (array[i+1]).num) < 0) || (strcmp((array[i+1]).num, (array[i]).num) > 0))
					{
						buf = array[i];
						array[i] = array[i+1];
						array[i+1] = buf;
						sorted = 0;
					}
				}
			}
		}
		else if (strcmp(pole, "3") == 0)
		{
			int sorted = 0;
			node buf;

			while(!sorted)
			{
				sorted = 1;

				for (int i = 1; i <= len - 2; i = i + 2) 
				{
					if ((array[i]).age < (array[i + 1]).age)
					{
						buf = array[i];
						array[i] = array[i+1];
						array[i+1] = buf;
						sorted = 0;
					}
				}

				for (int i = 0; i <= len - 2; i = i + 2) 
				{
					if ((array[i]).age < (array[i + 1]).age)
					{
						buf = array[i];
						array[i] = array[i+1];
						array[i+1] = buf;
						sorted = 0;
					}
				}
			}
		}
	}

 	//Запись файла
 	for (int i = 0; i < len; i++)
 	{
 		fprintf(file,"%s,%s,%d\n", (array[i]).name, (array[i]).num, (array[i]).age);
 	}



	fclose(file);
}

void selection_sort(node *array, int len, char *pole, char *nap, char *output)
{
	FILE *file = fopen(output, "w");
	node buf;

	if (strcmp(nap, "up") == 0)
	{
		int min_index = 0;
		if (strcmp(pole, "1") == 0)
		{
			for (int i = 0; i < len-1; i++)
			{
				min_index = i;
				for (int j = i+1; j < len; j++)
				{
					if ((strcmp((array[j]).name, (array[min_index]).name) < 0) || (strcmp((array[min_index]).name, (array[j]).name) > 0))
					{
						min_index = j;
					}
				}
				if (min_index != i)
				{
					buf = array[min_index];
					array[min_index] = array[i];
					array[i] = buf;
				}
			}
		}
		else if (strcmp(pole, "2") == 0)
		{
			for (int i = 0; i < len-1; i++)
			{
				min_index = i;
				for (int j = i+1; j < len; j++)
				{
					if ((strcmp((array[j]).num, (array[min_index]).num) < 0) || (strcmp((array[min_index]).num, (array[j]).num) > 0))
					{
						min_index = j;
					}
				}
				if (min_index != i)
				{
					buf = array[min_index];
					array[min_index] = array[i];
					array[i] = buf;
				}
			}
		}
		else if (strcmp(pole, "3") == 0)
		{
			for (int i = 0; i < len-1; i++)
			{
				min_index = i;
				for (int j = i+1; j < len; j++)
				{
					if ((array[j]).age < (array[min_index]).age)
					{
						min_index = j;
					}
					if (min_index != i)
					{
						buf = array[min_index];
						array[min_index] = array[i];
						array[i] = buf;
					}
				}
			}
		}
	}
	else if (strcmp(nap, "down") == 0)
	{
		int min_index = 0;
		if (strcmp(pole, "1") == 0)
		{
			for (int i = 0; i < len-1; i++)
			{
				min_index = i;
				for (int j = i+1; j < len; j++)
				{
					if ((strcmp((array[j]).name, (array[min_index]).name) > 0) || (strcmp((array[min_index]).name, (array[j]).name) < 0))
					{
						min_index = j;
					}
				}
				if (min_index != i)
				{
					buf = array[min_index];
					array[min_index] = array[i];
					array[i] = buf;
				}
			}
		}
		else if (strcmp(pole, "2") == 0)
		{
			for (int i = 0; i < len-1; i++)
			{
				min_index = i;
				for (int j = i+1; j < len; j++)
				{
					if ((strcmp((array[j]).num, (array[min_index]).num) > 0) || (strcmp((array[min_index]).num, (array[j]).num) < 0))
					{
						min_index = j;
					}
				}
				if (min_index != i)
				{
					buf = array[min_index];
					array[min_index] = array[i];
					array[i] = buf;
				}
			}
		}
		else if (strcmp(pole, "3") == 0)
		{
			for (int i = 0; i < len-1; i++)
			{
				min_index = i;
				for (int j = i+1; j < len; j++)
				{
					if ((array[j]).age > (array[min_index]).age)
					{
						min_index = j;
					}
					if (min_index != i)
					{
						buf = array[min_index];
						array[min_index] = array[i];
						array[i] = buf;
					}
				}
			}
		}
	}


	
	//Запись файла
 	for (int i = 0; i < len; i++)
 	{
 		fprintf(file,"%s,%s,%d\n", (array[i]).name, (array[i]).num, (array[i]).age);
 	}

	fclose(file);
}


void quick_sort(node *array, int len, char *pole, char *nap, char *output)
{
	FILE *file = fopen(output, "w");


	if (strcmp(nap, "up") == 0)
	{
		if (strcmp(pole, "1") == 0)
		{
			qsort(array, len, sizeof(node), (int (*)(const void *, const void *)) cmp_name_up);
		}
		else if (strcmp(pole, "2") == 0)
		{
			qsort(array, len, sizeof(node), (int (*)(const void *, const void *)) cmp_num_up);
		}
		else if (strcmp(pole, "3") == 0)
		{
			qsort(array, len, sizeof(node), (int (*)(const void *, const void *)) cmp_age_up);
		}
	}
	else if (strcmp(nap, "down") == 0)
	{
		if (strcmp(pole, "1") == 0)
		{
			qsort(array, len, sizeof(node), (int (*)(const void *, const void *)) cmp_name_down);
		}
		else if (strcmp(pole, "2") == 0)
		{
			qsort(array, len, sizeof(node), (int (*)(const void *, const void *)) cmp_num_down);
		}
		else if (strcmp(pole, "3") == 0)
		{
			qsort(array, len, sizeof(node), (int (*)(const void *, const void *)) cmp_age_down);
		}
	}


	//Запись файла
 	for (int i = 0; i < len; i++)
 	{
 		fprintf(file,"%s,%s,%d\n", (array[i]).name, (array[i]).num, (array[i]).age);
 	}


	fclose(file);
}

int cmp_name_up(const node *p1, const node *p2)
{
	return strcmp(p1->name, p2->name);
}

int cmp_name_down(const node *p1, const node *p2)
{
	return -strcmp(p1->name, p2->name);
}

int cmp_num_up(const node *p1, const node *p2)
{
	return strcmp(p1->num, p2->num);
}

int cmp_num_down(const node *p1, const node *p2)
{
	return -strcmp(p1->num, p2->num);
}

int cmp_age_up(const node *p1, const node *p2)
{
	return p1->num - p2->num;
}

int cmp_age_down(const node *p1, const node *p2)
{
	return -(p1->num - p2->num);
}