#include "sort.h"
#include <stddef.h>

/**
 * heap_sort - implements the sift down heap sort
 * @array: array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
    /* Null check */
	if (array == NULL)
		return;
	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, size, &array[0], &array[i]);
		heapify(array, size, 0, i);
	}
}

/**
 * heapify - recusivelty heapifies the heap
 * @array: array to be heapified (and printed)
 * @size: size of array
 * @i: root node of the heap
 * @j: size
 */
void heapify(int *array, int size, int i, int j)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < j && array[left] > array[max])
		max = left;

	if (right < j && array[right] > array[max])
		max = right;

	if (max != i)
	{
		swap(array, size, &array[i], &array[max]);
		heapify(array, size, max, j);
	}
}

/**
 * swap - simple swap helper function
 * @array: array (to be called in print function)
 * @size: size of array (to be called in print function)
 * @i: one element to be swapped
 * @j: the other element to be swapped
 */
void swap(int *array, int size, int *i, int *j)
{
	int tmp = *i;

	*i = *j;
	*j = tmp;
	print_array(array, size);
}
