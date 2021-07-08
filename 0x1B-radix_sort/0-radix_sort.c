#include "sort.h"

/**
 * get_max - Implements the radix sort
 * @array: The array to be sort
 * @size: Number of elements in @array
 */
int get_max(int *array, size_t size) {

	int i;
	int max = array[0];
	int n = size;

	for (i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * radix_sort - Implements the radix sort
 * @array: The array to be sort
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	int bucket[10][10], bucket_cnt[10];
	int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
	int n = size;

	lar = get_max (array, n);
	while (lar > 0){
		NOP++;
		lar /= 10;
	}
	for (pass = 0; pass < NOP; pass++){
		for (i = 0; i < 10; i++){
				bucket_cnt[i] = 0;
		}
		for (i = 0; i < n; i++){
			r = (array[i] / divisor) % 10;
			bucket[r][bucket_cnt[r]] = array[i];
			bucket_cnt[r] += 1;
		}
		i = 0;
		for (k = 0; k < 10; k++){
			for (j = 0; j < bucket_cnt[k]; j++){
        		array[i] = bucket[k][j];
        		i++;
        	}
    	}
    	divisor *= 10;
    	print_array(array, size);
	}
}
