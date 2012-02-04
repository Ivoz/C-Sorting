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
  * Shell sort is a variation on insertion sort, similar to comb
  * being a variation on bubble. It runs insertion sort, but comparing
  * elements a large distance apart at first, enabling them to move
  * large distances down the list. The best list of gap sizes to use
  * is determined experimentally. This algorithm runs in O(n log(n)).
  */
void shell_sort(int arr[], int len)
{
	int i, j, g, k, temp;
	int gaps[] = {419858, 186603, 82934, 36859, 16381, 7280, 3235, 
		      1437, 638, 283, 125, 55, 24, 10, 4, 1};
	for (k = 0; k < 16; k++)
	{
		g = gaps[k];
		for (i = g; i < len; i++)
		{
			
			temp = arr[i];
			for (j = i; 
			     (j >= g) && (comp(temp, arr[j - g]) < 0);
			     j -= g)
			{
				move(arr + j - g,arr + j);
			}
			move(&temp, arr + j);
		}
	}
}
