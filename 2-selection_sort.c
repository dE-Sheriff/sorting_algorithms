#include "sort.h"

/**
 * swap - swaps items in array
 * @xp: first item to swep
 * @yp: second item to swap with
 * Return: void
*/

void swap(int *xp, int *yp)
{
	int temp = *xp;

	*xp = *yp;
	*yp = temp;
}


/**
 * selection_sort -  a function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, x;
	int *low_num;

	if ((array == NULL) || (size == 0))
		return;

	for (i = 0; i < size; i++)
	{
		low_num = &(array[i]);
		for ((x = i + 1); x < size; x++)
			low_num = (array[x] < *low_num) ? &(array[x]) : low_num;

		if (low_num != &(array[i]))
		{
			swap(&array[i], low_num);
			print_array(array, size);
		}
	}
}
