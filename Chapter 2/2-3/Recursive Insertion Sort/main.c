#include <stdio.h>

#define SIZE 1024

// Recursively sorts A[1 .. n] from least to greatest
void insertionSort(int* A, int n);

// Inserts A[n] into proper place on sorted subset A[1 .. n-1]
void insert(int* A, int n);

// Prints array to stdout i.e. "49 82 5 82 71 32\n"
void printArray(int* array, int length);

// Returns length (number of elements) of array
int getLength(int* array);


int main()
{
	int array[SIZE] = {82, 68, 29, 72, 57, 01, 38, 81, 55, 28, 79};
	int length = getLength(array);
	
	printArray(array, length);
	
	insertionSort(array, length - 1);
	
	printArray(array, length);
	
	return 0;
}

/*
insertSort(A, n)
1    if n > 1
2        insertSort(A, n-1)
3        insert(A, n)
*/

void insertionSort(int* A, int n)
{
	if (n > 0)
	{
		insertionSort(A, n-1);
		insert(A, n);
	}
}


/*
insert(A, n)
1    A_n = A[n]
2    i = n - 1
3    while i > 0 and A[i] > A_n
4        A[i + 1] = A[i]
5        i = i - 1
6    A[i + 1] = A_n
*/
void insert(int* A, int n)
{
	int A_n = A[n];
	int i;
	for (i = n - 1; i >= 0 && A[i] > A_n; i--)
	{
		A[i+1] = A[i];
	}
	A[i+1] = A_n;
	
	return;
}





/*/////////////////////////////////////////////////////////////////:
	Common utility and debug functions for array data type.
*//////////////////////////////////////////////////////////////////:

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
