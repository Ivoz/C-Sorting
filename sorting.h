#ifndef __sorting_
#define __sorting_
#define DEFAULT_RANGE 1000
#define HANDOFF 10

void shuffle(int arr[], int len);

void move(int *j, int *k);

void swap(int *j, int *k);

int comp(int j, int k);

void print(int arr[], int len);

void insertion_sort(int arr[], int len);
void selection_sort(int arr[], int len);
void bubble_sort(int arr[], int len);
void cocktail_sort(int arr[], int len);
void comb_sort(int arr[], int len);
void shell_sort(int arr[], int len);
void quick_sort(int arr[], int len);
void merge_sort(int arr[], int len);
void heap_sort(int arr[], int len);

typedef struct sort_alg {
	void (*func)(int *, int);
	char *name;
} sort_alg_t;

#endif // #ifndef __sorting_
