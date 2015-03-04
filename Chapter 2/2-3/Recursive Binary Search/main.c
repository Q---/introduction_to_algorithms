#include <stdio.h>
#include <limits.h>

#define SIZE 1024

// Recursively searches subarray A[left .. right-1]
int binarySearch(int* A, int key, int left, int right);



///////////////////////////////////////////////////////////
// Sorting functions for array O(n lg n)
///////////////////////////////////////////////////////////

// Merges subset of array A[p .. r-1] in-place.  Do mergeSort(A, 0, length) to sort completely
void mergeSort(int* array, int p, int r);

// Merges sorted subset of array A[q .. p-1] with sorted subset A[p .. r-1]
void merge(int* array, int q, int p, int r);

///////////////////////////////////////////////////////////
// Utility and debug functions for array data type
///////////////////////////////////////////////////////////

// Prints array to stdout i.e. "49 82 5 82 71 32\n"
void printArray(int* array, int length);

// Returns length (number of elements) of array
int getLength(int* array);


int main()
{
	int A[SIZE] = {82, 68, 29, 72, 57, 01, 38, 81, 55, 28, 79};
	int length = getLength(A);
	
	mergeSort(A, 0, length);
	printArray(A, length);
	
	int i;
	i = binarySearch(A, 55, 0, length);
	
	printf("%i\n", i);
	
	return 0;
}

/*
binarySearch(A, key, p, r)
1    if p < r
2        q = floor((p+r)/2)
3        if A[q] < key
4            return binarySearch(A, key, p, q-1)
5        else if A[q] > key
6            return binarySearch(A, key, q, r)
7        else return q
8    else return NIL
*/

int binarySearch(int* A, int key, int left, int right)
{
	if (left + 1 < right)
	{
		int mid = (left+right)/2;
		int A_mid = A[mid];
		if (A_mid > key)
		{
			return binarySearch(A, key, left, mid);
		}
		else if (A_mid < key)
		{
			return binarySearch(A, key, mid, right);
		}
		else
		{
			return mid;
		}
	}
	else
	{
		return -1;
	}
}




///////////////////////////////////////////////////////////
// Sorting functions for array O(n lg n)
///////////////////////////////////////////////////////////

/*
Merge-Sort(A, p, r)
if p < r
	q = floor( (q + r)/2 )
	Merge-Sort(A, p, q)
	Merge-Sort(A, q + 1, r)
	Merge(A, p, q, r)
*/

void mergeSort(int* array, int left, int right)
{
	if (left + 1 < right)
	{
		int mid = (left+right)/2;
		mergeSort(array, left, mid);
		mergeSort(array, mid, right);
		merge(array, left, mid, right);
	}
}


/*
Merge(A, p, q, r)
	n1 = q - p + 1
	n2 = r - q
	let L[1..n1+1] and R[1..n2+1] be new arrays
	for i = 1 to n1
		L[i] = A[p + i - 1]
	for j = 1 to n2
		R[j] = A[q + j]
	L[n1 + 1] = inf
	R[n2 + 1] = inf
	i = 1
	j = 1
	for k = p to r
		if L[i] <= R[j]
			A[k] = L[i]
			i = i + 1
		else A[k] = R[j]
			j = j + 1
*/

void merge(int* A, int left, int mid, int right)
{
	int L_length = mid - left;
	int R_length = right - mid;
	
	
	int i;
	int L[L_length+1]; // Initialize left subset to be merged
	for (i = 0; i < L_length; i++)
	{
		L[i] = A[left + i]; // Copy subset of A into newly initialized array
	}
	L[L_length] = INT_MAX;
	
	int R[R_length+1]; // Initialize right subset to be merged
	for (i = 0; i < R_length; i++)
	{
		R[i] = A[mid + i]; // Copy subset of A into newly initialized array
	}
	R[R_length] = INT_MAX;
	
	int L_index = 0;
	int R_index = 0;
	for (i = left; i < right; i++)
	{
		if (L[L_index] <= R[R_index])
		{
			A[i] = L[L_index++];
		}
		else
		{
			A[i] = R[R_index++];
		}
	}
	
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
