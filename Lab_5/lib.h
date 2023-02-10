#ifndef _LIB_H
#define _LIB_H

//Структуры
typedef struct node
{
	int age;
	char *name;
	char *num;

	
}node;

//Методы
void print_help();
void task(char *,char *,char *,char *,char *);
int flags_check(char *, char *, char *);
void odd_even_sort(node *, int , char *, char *, char *);
void selection_sort(node *, int , char *, char *, char *);
void quick_sort(node *, int , char *, char *, char *);
int cmp_name_up(const node *, const node *);
int cmp_name_down(const node *, const node *);
int cmp_num_up(const node *, const node *);
int cmp_num_down(const node *, const node *);
int cmp_age_up(const node *, const node *);
int cmp_age_down(const node *, const node *);




#endif