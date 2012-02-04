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
  * Insertion sort works by conceptually partitioning the list 
  * into two parts, one sorted and one not. Each successive
  * element is then moved down into the sorted partition.
  * It is an O(n^2) algorithm, but is very efficient for small or
  * nearly-ordered lists. For this reason it is often used 
  * inside other algorithms to finish sorting small parts of,
  * or a nearly ordered list.
  */
void insertion_sort(int arr[], int len)
{
	int i, j, temp;
	// Elements below i are considered already in sorted order
	for (i = 1; i < len; i++)
	{
		temp = arr[i];
		for (j = i; j > 0 
		     && comp(temp, arr[j - 1]) < 0; j--)
		{
			move(arr + j - 1,arr + j);
		}
		move(&temp, arr + j);
	}
}
