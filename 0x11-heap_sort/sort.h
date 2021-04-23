#ifndef _SORT_H
#define _SORT_H

#include <stdlib.h>

void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void swap(int *array, int size, int *a, int *b);
void heapify(int *array, int n, int i, int size);


#endif /* _SORT_H */
