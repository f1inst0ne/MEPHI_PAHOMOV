#ifndef _LIB_H
#define _LIB_H



typedef struct node
{

	struct node* prev;
	struct node* next;
	char data;


}node;

typedef struct List
{
	node *head;
	node *tail;
}List;


List *init_list();
void push_head(List *,char);
void push_tail(List *,char);

void print_list(List *);
void pop_head(List **);
void free_list(List **);
void fill_list(List **);
int count_letter(List *, char);
char check_letter(List *);
node *pop_node(node *, List **);
int check_next(node *);
int check_prev(node *);
void task(List **list);

#endif