#include "sort.h"

/**
 * q_swap - swaps items in array
 * @xp: first item to swep
 * @yp: second item to swap with
 * Return: void
 */

void q_swap(int xp, int yp)
{
	int temp = xp;

	xp = yp;
	yp = temp;
}

/**
 * l_partition - implements the the required partitioning
 * using the lomuto scheme
 * @arr: the array to partition
 * @start: the start of the array
 * @end: the end of the array
 * @size: size of array
 * Return: returns partiton index
 */
int l_partition(int *arr, int start, int end, size_t size)
{
	int  pivot;
	int index, x;

	pivot =  arr[end];
	index = start;

	for (x = start; x < end; x++)
	{
		if (arr[x] <= pivot)
		{
			if (index < x)
			{
				if (arr[index] != arr[x])
					q_swap(arr[index], arr[x]);
				print_array(arr, size);
			}
			index++;
		}
	}
	if (arr[index] > pivot)
	{
		q_swap(arr[index], arr[end]);
		print_array(arr, size);
	}
	return (index);
}

/**
 * l_sorter - implements the quick sorter
 * @start: start of array
 * @end: end of array
 * @arr: the array itself
 * @size: size of array
 * Return: void
 */

void l_sorter(int *arr, int start, int end, size_t size)
{
	int index;

	if (start >= end || start < 0)
		return;

	index = l_partition(arr, start, end, size);
	l_sorter(arr, start, index - 1, size);
	l_sorter(arr, index + 1, end, size);
}
/**
 * quick_sort - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: the array to sort
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	int start = 0, end = size - 1;

	if (array == NULL || size < 2)
		return;

	l_sorter(array, start, end, size);
}
