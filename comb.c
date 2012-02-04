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
  * Comb sort is an improved bubble sort. It improves by
  * starting off trying to swap elements far away from eachother,
  * determined by the size of a gap. It slowly lowers the gap to 1,
  * where it becomes a bubble sort to sort all remaining out of
  * order elements. Because of this improvement, it is 
  * an O(n log(n)) sort.
  */
void comb_sort(int arr[], int len)
{
	int i, gap = len;

	while (gap > 2)
	{
		gap = (int)((double)gap / 1.247330950103979);

		// A small optimization, as gap reductions starting
		// from 11 are more efficient than 9 or 10.
		if (gap == 9 || gap == 10) { gap = 11; }
		
		// Alternatively, selection sort may be used to sort
		// the almost sorted list, below a certain gap size.
		/* if (gap < 11) */
		/* { */
		/* 	insertion_sort(arr, len); */
		/* 	return; */
		/* } */
		
		for (i = 0; gap + i < len; i++)
		{
			if (comp(arr[i],arr[i + gap]) > 0)
			{
				swap(arr + i, arr + i + gap);
			}
		}
	}
	// Do a final bubble sort
	bubble_sort(arr, len);
}
