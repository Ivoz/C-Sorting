 /**
  * Copyright 2012 Matthew Iversen
  *
  * This code is licensed under a 
  * Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
  *
  * Please see the LICENSE file distributed with this code for the full
  * license.
  */

#include "../sorting.h"

 /*
  * Selection sort works by selecting the minimum element in
  * the list, and swapping it too the bottom. It then repeats this
  * procedure for the rest of the list. An O(n^2) algorithm, it 
  * generally performs worse than insertion sort, but makes fewer 
  * writes.
  */
void selection_sort(int arr[], int len)
{
	int min, pos, i;
	// Iterate through all positions in the array
	for (pos = 0; pos < len; pos++)
	{
		// Find the smallest value in the rest of the array
		min = pos;
		for (i = pos + 1; i < len; i++)
		{
			if (comp(arr[i], arr[min]) < 0)
			{
				min = i;
			}
		}
		// Swap it into position
		if (min != pos)
		{
			swap(arr + min,arr + pos);
		}
	}
}
