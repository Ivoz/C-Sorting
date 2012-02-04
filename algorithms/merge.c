 /**
  * Copyright 2012 Matthew Iversen
  *
  * This code is licensed under a 
  * Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
  *
  * Please see the LICENSE file distributed with this code for the full
  * license.
  */

#include <string.h>
#include <stdlib.h>
#include "../sorting.h"

void partition(int arr[], int len, int merger[]);
void merge(int a[], int lena, int b[], int lenb, int merger[]);

 /*
  * Merge sort is a divide-and-conquer algorithm. It divides the array
  * into two, sorts each half, and then merges each half into a fully
  * sorted array. The merging process needs another array to merge into,
  * so merge sort usually takes an extra O(n) space, as opposed to other
  * in-place algorithms. When the length of the array is small, it can
  * be helpful to sort it with a simpler insertion sort, that will be 
  * faster for those sizes. It is an O(n log(n)) algorithm.
  */
void merge_sort(int arr[], int len)
{
	// Allocate space for merging array
	int *merger;
	merger = malloc(sizeof(*merger) * len);
	// Sort into array merger
	partition(arr, len, merger);
	free(merger);
}

// Partition the array into two, and sort each partition
// merger must be of the same length as arr
void partition(int arr[], int len, int merger[])
{
	/* if (len < 2) return; */
	// Hand off to insertion sort for small arrays
	if (len < HANDOFF)
	{
		insertion_sort(arr, len);
		return;
	}
	int i = len / 2;
	partition(arr, i, merger);
	partition(arr + i + 1, len - i, merger + i + 1);
	merge(arr, i, arr + i + 1, len - i, merger);
	// Copy back into original array
	memcpy(arr, merger, sizeof(*merger) * len);
}

// Merge two sorted arrays into merger
void merge(int a[], int lena, int b[], int lenb, int merger[])
{
	while (lena > 0 && lenb > 0)
	{
		if (comp(*a, *b) < 0)
		{
			move(a++, merger++);
			lena--;
		}
		else
		{
			move(b++, merger++);
			lenb--;
		}
	}
	while (lena > 0)
	{
		move(a++, merger++);
		lena--;
	}
	while (lenb > 0)
	{
		move(b++, merger++);
		lenb--;
	}
}
