/*
this library defines a few commonly used sort algorithms.
*/
#include "sort_lib.h"
#include <stdlib.h>

void bubble_sort(int x[],int array_size){
	int N = array_size;
	int i,j,temp;
	for(i = 0; i <= N - 2; i++){
		for(j = 0; j <= N - 2 - i; j++){
			if(x[j+1] < x[j]){
				temp = x[j+1];
				x[j+1] = x[j];
				x[j] = temp;
			}
		}
	}
}

void insertion_sort(int x[],int array_size){
	int N = array_size;
	int v,j;
	for(int i = 1; i <= N-1; i++){
		v = x[i];
		j = i - 1;
		while(j >= 0 && x[j] > v){
			x[j+1] = x[j];
			j = j - 1;
		}
		x[j+1] = v;
	}
}

void selection_sort(int x[],int array_size){
	int N = array_size;
	int i,j,min,temp;
	for(i = 0; i <= N - 2; i++){
		min = i;
		for(j = i + 1; j <= N - 1; j++){
			if(x[j] < x[min]){
				min = j;
			}
		}
		temp = x[i];
		x[i] = x[min];
		x[min] = temp;
	}
}


void merge_sort(int a[], int array_size){
	if (array_size > 1){
		//dynamic allocation of the memory in the HEAP section
		int* b = (int*)calloc((array_size/2),sizeof(int)); 
		int* c = (int*)calloc((array_size - (array_size/2)),sizeof(int)); 
		for( int k = 0; k < array_size/2; k++){
			b[k] = a[k];
		}
		for( int k = 0; k < (array_size - (array_size/2)); k++){
			c[k] = a[array_size/2 + k];
		}

		merge_sort(b,array_size/2);
		merge_sort(c,(array_size - (array_size/2)));
		merge(b,array_size/2,c,(array_size - (array_size/2)),a);
		//release the memory allocated in the HEAP section 
		free(b);
		free(c);
	}
}

void merge(int b[], int n1, int c[], int n2, int a[]){
	int i = 0, j = 0, k = 0;
	while(i < n1 && j < n2){
		if (b[i] <= c[j]){
			a[k] = b[i];
			i++;
		}
		else{
			a[k] = c[j];
			j++;
		}
		k++;
	}
	if ( i == n1){
		for (int m = j; m <= n2 - 1; m++){
			a[k+m-j] = c[m];
		}
	}
	else{
		for (int m = i; m <= n1 - 1; m++){
			a[k+m-i] = b[m];
		}
	}
}

void quick_sort(int x[], int l, int r){
	if ( l < r){
		int s = partition(x,l,r);
		quick_sort(x,l,s-1);
		quick_sort(x,s+1,r);
	}
}

int partition(int x[], int l, int r){
	int p = x[l], i = l, j = r+1;
	do{
		do{
			i++;
		}while(x[i] < p);
		
		do{
			j--;
		}while(x[j] > p);
		
		swap(&x[i],&x[j]);
		
	}while(i < j);
	
	swap(&x[i],&x[j]);
	swap(&x[l],&x[j]);
	return j;
}

void swap(int* a, int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}