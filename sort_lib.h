/*
this header file delcares the functions defined in sort_lib.c
*/
#ifndef SORT_LIB
#define SORT_LIB

//sort functions to be called by the user programs
void bubble_sort(int x[],int array_size);
void insertion_sort(int x[],int array_size);
void selection_sort(int x[],int array_size);
void merge_sort(int x[],int array_size);
void quick_sort(int x[], int l, int r);

//utility functions which are called by the respective sort functions
void merge_sort(int a[], int array_size);
int partition(int x[], int l, int r);
void swap(int* a, int* b);

#endif