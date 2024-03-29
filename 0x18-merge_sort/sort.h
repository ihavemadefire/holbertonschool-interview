#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>

void custom_print(char *slug, int *array, size_t size);
void merge_sort_rec(int *array, size_t size, int *aux);
void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);

#endif
