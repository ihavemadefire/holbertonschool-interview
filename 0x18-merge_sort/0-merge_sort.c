#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * custom_print - print an array in  predicatble way
 * @slug: leading text
 * @array: the array to print
 * @size: the size of the array
 */
void custom_print(char *slug, int *array, size_t size)
{
	size_t i = 0;

	printf("%s", slug);
	for (i = 0; i < size; i++)
	{
		printf("%i", array[i]);
		if (i == size - 1)
		{
			printf("\n");
			return;
		}
		printf(", ");
	}
}

/**
 * merge_sort_rec - merges the previously divided lists
 *
 * @array: array to be sorted
 * @size: size of array
 * @aux: empty array
 */
void merge_sort_rec(int *array, size_t size, int *aux)
{
	size_t mid = size / 2;
	size_t i = 0;
	size_t j = mid;
	size_t k = 0;

    /* break condition if recursed to array of 1 or NULL */
	if (size <= 1 || array == NULL)
	{
		return;
	}

    /* split up unsorted list */
	merge_sort_rec(array, mid, aux);
	merge_sort_rec(array + mid, size - mid, aux);
	printf("Merging...\n");
	custom_print("[left]: ", array, mid);
	custom_print("[right]: ", array + mid, size - mid);

    /* Merge*/
	while (i < mid && j < size)
	{
		if (array[i] < array[j])
		{
			aux[k] = array[i];
			i++;
		}
		else
		{
			aux[k] = array[j];
			j++;
		}
		k++;
	}
	for ( ; i < mid; i++, k++)
		aux[k] = array[i];
	for ( ; j < size; j++, k++)
		aux[k] = array[j];
	for (k = 0; k < size; k++)
		array[k] = aux[k];
	custom_print("[Done]: ", array, size);
}

/**
 * merge_sort - executes the merge sort
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */

void merge_sort(int *array, size_t size)
{
	int *aux = NULL;

	if (array == NULL || size == 0)
		return;
	aux = malloc(size * sizeof(int));
	if (aux == NULL)
		return;
	merge_sort_rec(array, size, aux);
	free(aux);

}
