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

void heapify(int arr[], int len);
void sift_down(int arr[], int node, int len);

 /*
  * Heap sort is an adaption of selection sort, but using a max-heap
  * to select and place the max element of the unsorted array, 
  * rather than naively searching the array for it. First the array
  * is 'heapified', so that the max element resides at the root of the
  * heap. It is then swapped to the end, and the array sifted to restore
  * its heap property, so the next largest element can be swapped out.
  * It is an O(n log(n)) in-place algorithm, and can be used for 
  * smaller sections of quick sort to avoid its pivot selection problem.
  */
void heap_sort(int arr[], int len)
{
	heapify(arr, len);
	for (len--; len > 0; len--)
	{
		// swap the max value to the end
		swap(arr, arr + len); 
		// sift the new root into heap order
		sift_down(arr, 0, len); 
	}
}

// Build a max-heap with the root at 0
void heapify(int arr[], int len)
{
	// Start from the first parent with a child
	int start = len / 2 - 1;
	// Sift each element down, if it is not in heap order
	for (; start >= 0; start--)
	{
		sift_down(arr, start, len);
	}
}

// Sift a node in a heap down; restores the heap property for that node
// Moving down here refers to moving down the heap tree, not moving
// up array indices.
void sift_down(int arr[], int node, int len)
{
	arr--, node++; // Use a 1 based index for nicer calculations
	int next; // holds the index to swap the node with

	while (2 * node <= len)
	{
		next = node;
		// Check left child
		if (comp(arr[next], arr[node * 2]) < 0)
		{
			next = node * 2;
		}
		// Check right child
		if (node * 2 + 1 <= len
			&& comp(arr[next], arr[node * 2 + 1]) < 0)
		{
			next = node * 2 + 1;
		}
		// Swap down, if node is smaller than either
		if (next != node)
		{
			swap(arr + node, arr + next);
			node = next;
		}
		else
		{
			return;
		}
	}
}
