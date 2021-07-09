#include "sort.h"


/**
 * radix_recursive - A recursive implementation of the radix sort
 * @array: The array to be sorted
 * @size: The size of the array to be sorted
 * @digit: the current digit to sort by
 */
void radix_recursive(int *array, size_t size, size_t digit)
{
	size_t i = 0, j = 0;
	size_t digits[10] = {0};
	int *rads[10];
	int tmp, count;

	for (i = 0; i < size; i++)
	{
		tmp = (array[i] % digit) / (digit / 10);
		digits[tmp] = digits[tmp] + 1;
	}
	if (digits[0] == size)
		return;
	for (i = 0; i < 10; i++)
		rads[i] = malloc(digits[i] * sizeof(int));
	for (i = 0; i < 10; i++)
	{
		count = 0;
		for (j = 0; j < size; j++)
			if (((array[j] % digit) / (digit / 10)) == i)
			{
				rads[i][count] = array[j];
				count++;
			}
	}
	count = 0;
	for (i = 0; i < 10; i++)
		for (j = 0; j < digits[i]; j++)
		{
			array[count] = rads[i][j];
			count++;
		}
	print_array((const int *)array, size);
	for (i = 0; i < 10; i++)
		free(rads[i]);
	radix_recursive(array, size, digit * 10);
}


/**
 * radix_sort - Wrapper funtion for radix sort
 * @array: The array to be sorted
 * @size: The size of the array to be sorted
 */
void radix_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	if (size < 2)
		return;
	radix_recursive(array, size, 10);
}
