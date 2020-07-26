// C program to find second largest 

#include <limits.h> 
#include <stdio.h> 

int print2largest(int arr[], int arr_size) 
{ 
	int i, first, second; 

	if (arr_size < 2) { 
		printf(" Invalid Input "); 
		return 0; 
	} 

	first = second = INT_MIN; 
	for (i = 0; i < arr_size; i++) { 
		if (arr[i] > first) { 
			second = first; 
			first = arr[i]; 
		} 

		else if (arr[i] > second && arr[i] != first) 
			second = arr[i]; 
	} 
	if (second == INT_MIN) 
		return -1;
	else
		return second;
} 

int main() 
{ 
  int arrsize,i;
printf("enter a size of array:");
  scanf("%d",&arrsize);
printf("enter a array data:");
	int arr[arrsize];
  for(i=0;i<arrsize;i++) 
    scanf("%d",&arr[i]);
	 
	printf("output=%d\n",print2largest(arr,arrsize)); 

	return 0; 
}
