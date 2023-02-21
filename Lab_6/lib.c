#include<stdio.h>
#include<stdlib.h>
#include"lib.h"


List *init_list()
{
	List *tmp = (List*)malloc(sizeof(List));
	tmp->head = NULL;
	tmp->tail = NULL;

	return tmp;
}

void push_head(List *list,char letter) {
    node *tmp = (node*) malloc(sizeof(node));
    tmp->data = letter;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;
 
    if (list->tail == NULL) {
        list->tail = tmp;
    }
}
void push_tail(List *list,char letter) {
    node *tmp = (node*) malloc(sizeof(node));
    tmp->data = letter;
    tmp->prev = list->tail;
    tmp->next = NULL;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;
 
    if (list->head == NULL) {
        list->head = tmp;
    }
}



void print_list(List *list)
{
	node *tmp = list->head;

	while(tmp)
	{
		printf("%c", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

//Заполнение списка символами
void fill_list(List **list)
{
	char data = '\0';
	while(data != '\n')
	{
		data = getchar();
		push_tail((*list), data);
	}
}



//Удаление по указателю head 
void pop_head(List **list)
{
	node *tmp = (*list)->head;
	(*list)->head = (*list)->head->next;
	if ((*list)->head == NULL)
	{
		free(tmp);
		return;
	}
	free(tmp);
}




node *pop_node(node *item, List **list)
{
	node *elem= item->next;
	if ((check_next(item)) && !(check_prev(item)))
	{
		(*list)->tail = item->prev;
		item->prev->next = NULL;
	}
	else if (!(check_next(item)) && (check_prev(item)))
	{
		(*list)->head = item->next;
		item->next->prev = NULL;
	}
	else
	{
		item->prev->next = item->next;
		item->next->prev = item->prev;
	}
	
	free(item);

	return elem;
}



int check_next(node *item)
{
	if (item->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int check_prev(node *item)
{
	if (item->prev == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}





void task(List **list)
{
	node *tmp = (*list)->head;
	char letter = check_letter((*list));
	
	while (tmp)
	{
		if (tmp->data == letter)
		{
			while ((tmp->prev != NULL) && (tmp->prev->data != ' '))
			{

				pop_node(tmp->prev, &(*list));
			}
			if (tmp->next->next == NULL)
			{
				tmp = pop_node(tmp, &(*list));
				break;
			}
			while (tmp->next->data != ' ')
			{
				pop_node(tmp->next, &(*list));
			}
			tmp = pop_node(tmp, &(*list));
			tmp = pop_node(tmp, &(*list));
		}
		tmp = tmp->next;
	}

	
}

//Отчистка всего в list, кроме самого указателя list
void free_list(List **list)
{
	while((*list)->head)
	{
		pop_head(&(*list));
	}
}

//Проверяет весь список и возвращает наиболее встречающийся символ
char check_letter(List *list)
{
	int max_counter = 0;
	char letter;
	node *tmp;
	tmp = list->head;
	while (tmp)
	{
		if (tmp->data == ' ')
		{
			tmp = tmp->next;
			continue;
		}
		if (count_letter(list, tmp->data) > max_counter)
		{
			letter = tmp->data;
			max_counter = count_letter(list, tmp->data);
		}
		tmp = tmp->next;
	}

	return letter;
}

//Считает сколько раз встречается символ с списке
int count_letter(List *list, char letter)
{
	int counter = 0;
	node *tmp;
	tmp = list->head;
	while (tmp)
	{
		if (tmp->data == letter)
		{
			counter++;
		}
		tmp = tmp->next;
	}

	return counter;
}



