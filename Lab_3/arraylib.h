#ifndef _arraylib_h
#define _arraylib_h

int *init_array(int);
int *copy_array(int *, int);
int *add_to_end(int *, int);
int *add_by_index(int *, int);
int *del_by_index(int *, int);
void print_array(int, int *);
int *del_by_known_index(int *, int, int);
int *add_to_end_known(int *, int, int);
#endif
