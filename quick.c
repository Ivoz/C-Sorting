 /**
  * Copyright 2012 Matthew Iversen
  *
  * This code is licensed under a 
  * Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
  *
  * Please see the LICENSE file distributed with this code for the full
  * license.
  */

#include "sorting.h"

 /*
  * Quick sort is practically one of the fastest sorting algorithms.
  * It uses an iterative divide-and-conquer technique, by choosing one
  * element of the array, called the pivot, and partitioning the
  * elements as either higher or lower than the pivot. The two 
  * partitions can then be sorted, the pivot insert in between, and a
  * sorted array results. It takes O(n log(n)) time, but can be made
  * slow by structuring the array to contain bad pivot points. For this
  * implementation, such a structure is simply an already sorted array. 
  * Switching to a simpler insertion sort for small arrays can provide
  * speed-up over quick-sorting 'all the way down'.
  */
void quick_sort(int arr[], int len)
{
	// Use this for a pure quicksort
	/* if (len < 2) return; */ 

	// Hand off to insertion sort for small arrays
	if (len < HANDOFF)
	{
		insertion_sort(arr, len);
		return;
	}

	int pivot, part = 0, i = 0;
	
	// A median of the first, middle, last element can be used as
	// the pivot, to lessen the posibility of a bad pivot choice.
	/* if (comp(arr[0], arr[len - 1]) > 0) */
	/* 	swap(arr, arr + len - 1); */
	/* if (comp(arr[0], arr[len / 2]) <= 0 */ 
	/* 		&& comp(arr[len / 2], arr[len - 1]) <= 0) */
	/* 	swap(arr + len / 2, arr + len - 1); */
	/* else if (comp(arr[len / 2], arr[0]) <= 0 */
	/* 		&& comp(arr[0], arr[len - 1]) <= 0) */
	/* 	swap(arr, arr + len - 1); */

	pivot = arr[len - 1];
	// partition array
	for (; i < len - 1; i++)
	{
		if (comp(arr[i], pivot) < 0)
		{
			swap(arr + i,arr + part++);
		}
	}
	swap(arr + part, arr + len - 1);
	// sort partitions
	quick_sort(arr, part);
	quick_sort(arr + part, len - part);
}
