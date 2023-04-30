#include "sort.h"

/**
 * bubble_sort - sorts numbers by making the big ones bubble to the top
 * @array: array of numbers to sort
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp;
	short swaps;

	for (swaps = 1; swaps == 1;)
	{
		swaps = 0;
		for (i = 0; (i + 1) < size; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				swaps = 1;
			}
		}
	}
}
