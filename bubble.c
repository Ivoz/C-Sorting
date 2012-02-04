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
  * Bubble sort works by 'bubbling' large elements up to the top
  * of the list, through swapping out-of-order adjacent elements 
  * while scanning upwards through the list. It continues doing 
  * this until the list is sorted. This implementation is optimized 
  * by realizing that all elements after the last swap performed 
  * must already be sorted. Bubble sort is generally an O(n^2) 
  * algorithm, but runs linearly on an already-sorted list.
  */
void bubble_sort(int arr[], int len)
{
	int i, swapped = 1;
	// We are finished if no swapping has been done.
	while (swapped > 0)
	{
		swapped = 0;
		for (i = 1; i < len; i++)
		{
			if (comp(arr[i], arr[i - 1]) < 0)
			{
				swap(arr + i, arr + i - 1);
				swapped = i;
			}
		}
		// Only sort up to the last swapped element
		len = swapped;
	}
}
