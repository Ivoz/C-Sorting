 /**
  * Copyright 2012 Matthew Iversen
  *
  * This code is licensed under a 
  * Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
  *
  * Please see the LICENSE file distributed with this code for the full
  * license.
  */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "sorting.h"

// getopt params
extern char *optarg;
extern int optind, opterr, optopt;

sort_alg_t algs[] = {{ insertion_sort, "insertion" },
		     { selection_sort, "selection" },
		     { bubble_sort, "bubble" },
		     { cocktail_sort, "cocktail" },
		     { comb_sort, "comb" },
		     { shell_sort, "shell" },
		     { quick_sort, "quick" },
		     { merge_sort, "merge" },
		     { heap_sort, "heap" }};
int num_algs = 9;

long range = DEFAULT_RANGE;
long num_comps = 0, num_moves = 0;
int show_comps = 0, show_moves = 0;

void sort(int i, int arr[], int len);

int main(int argc, char *argv[])
{
	if (argc < 2)
		{ printf("Use %s -h for usage\n", argv[0]); return 0; }
	int c, n = -1;
	char chosen_alg[20];
	strncpy(chosen_alg,"quick",20);
	while ((c = getopt(argc, argv, "+a:chlmr:")) != -1)
	{
		switch (c)
		{
		case 'a':
			strncpy(chosen_alg,optarg,19);
			break;
		case 'c':
			show_comps = 1;
			break;
		case 'l':
			for (int i = 0; i < num_algs; i++)
				{ printf("%s\n", algs[i].name); }
			return 0;
			break;
		case 'r':
			range = atoi(optarg);
			break;
		case 'm':
			show_moves = 1;
			break;
		case '?':
			return 0;
		case 'h':
			printf("Demonstration of sorting algorithms. Options:\n");
			printf("-a name   -- Name of algorithm to sort by\n");
			printf("-c        -- Show number of comparisons\n");
			printf("-h        -- This help\n");
			printf("-l        -- List algorithms\n");
			printf("-m        -- Show number of moves\n");
			printf("-r n      -- Sort n elements\n");
			return 0;
			break;
		}
	}
	// Create and shuffle the array
	int *array;
	array = malloc(sizeof(*array) * range);
	for (int i = 0; i < range; ++i)
		{ array[i] = i; }
	shuffle(array, range);
	// Reset moves
	// Find correct algorithm
	for (int i = 0; i < num_algs; ++i)
	{
		if (strcmp(chosen_alg,algs[i].name) == 0)
		{
			n = i;
			break;
		}
	}
	if (n >= 0)
	{
		sort(n, array, range);
		n = 0;
	}
	else
	{
		printf("No algorithm of named %s\n", chosen_alg);
		n = 1;
	}
	free(array);
	return n;
}

void sort(int i, int arr[], int len)
{
	num_comps = 0;
	num_moves = 0;
	algs[i].func(arr, len);
	if (show_comps)
	{
		printf("Comparisons: %ld\n", num_comps);
	}
	if (show_moves)
	{
		printf("Moves:       %ld\n", num_moves);
	}
	// Assert that the array is sorted!
	for (int j = 0; j < len - 1; j++)
	{
		assert(comp(arr[j],arr[j+1]) <= 0);
	}
}

// fisher-yates shuffle
void shuffle(int arr[], int len)
{
	// Initialise RNG
	int randomData = open("/dev/random", O_RDONLY);
	unsigned int rand_int;
	read(randomData, &rand_int, sizeof rand_int);
	srandom(rand_int);
	close(randomData);
	random();
	int i, j;
	for (i = len - 1; i > 0; --i)
	{
		j = random() % (i + 1);
		swap(arr + i,arr + j);
	}
}

// move one element to another
void move(int *j, int *k)
{
	num_moves++;
	*k = *j;
}

// swap two elements
void swap(int *j, int *k)
{
	num_moves += 3;
	int temp = *j;
	*j = *k;
	*k = temp;
}

// Comparison function
int comp(int j, int k)
{
	num_comps++;
	if (j < k)
		return -1;
	if (j == k)
		return 0;
	return 1;
}

// Debugging function, use to print out short arrays
void print(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

