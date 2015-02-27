#include <stdio.h>

#define SIZE 1024

// Sorts array using in-place selection-sort algorithm
void selectionSort(int* array, int length);

// Prints array to stdout i.e. "49 82 5 82 71 32\n"
void printArray(int* array, int length);

// Returns length (number of elements) of array
int getLength(int* array);



int main()
{
	int array[SIZE] = {82, 68, 29, 72, 57, 01, 38, 81, 55, 28, 79};
	int length = getLength(array);
		
	selectionSort(array, length);
	printArray(array, length);
	
	return 0;
}

/*
Selection-Sort(A)
1    for j = 1 to A.length - 1
2        min = j
3        for i = j to A.length
4            if A[i] < A[j]
5                min = j
6        // Swap the numbers
7        t1 = A[j]
8        A[j] = A[min]
9        A[min] = t1
*/

void selectionSort(int* array, int length)
{
	int j;
	for (j = 0; j < length - 1; j++)
	{
		int min = j;
		int i;
		for (i = j; i < length; i++)
		{
			if (array[i] < array[min])
				min = i;
		}
		int t1 = array[j];
		array[j] = array[min];
		array[min] = t1;
	}
}

void printArray(int* array, int length)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		printf("%i ", array[i]);
	}
	printf("\n");
	
	return;
}

int getLength(int* array)
{
	int i = 0;
	for (i = 0; array[i]; i++)
	{
		;
	}
	
	return i;
}

