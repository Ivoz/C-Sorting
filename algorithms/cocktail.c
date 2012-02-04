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
 * Cocktail sort is a variation on bubble sort. While bubble sort
 * always operates up the array, 'bubbling' up elements, cocktail 
 * sort also works down the array, allowing it to move elements up
 * and down the array in one pass. This implementation is optimised
 * by realising that all elements before or after (depending on 
 * direction) the last swap are already sorted.
 */
void cocktail_sort(int arr[], int len)
{
	int i, start = 0, swapped = 0;
	while (start < len)
	{
		for (i = start + 1; i < len; i++) // going up
		{
			if (comp(arr[i], arr[i - 1]) < 0)
			{
				swap(arr + i, arr + i - 1);
				swapped = i;
			}
		}
		len = swapped;
		for (i = len - 1; i >= start; i--) // going down
		{
			if (comp(arr[i + 1], arr[i]) < 0)
			{
				swap(arr + i, arr + i + 1);
				swapped = i;
			}
		}
		start = swapped;
	}
}
