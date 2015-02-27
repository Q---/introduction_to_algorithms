#include <stdio.h>

int insertionSort(int*, int);

int insertionSort_decreasing(int*array, int length);

int printArray(int*, int);

int main()
{
	
	int array[1024] = {31, 41, 59, 26, 41, 58};
	
	int length;
	int i;
	for (i = 0; array[i]; i++)
		length = i + 1;
	
	insertionSort_decreasing(array, length);
	
	printArray(array, length);
	
	return length;
}

int insertionSort(int* array, int length)
{
	int i;
	int j;
	for (j = 1; j < length; j++)
	{	
		int key = array[j];
		i = j-1;
		
		while (i >= 0 &&  array[i] > key)
		{
			array[i+1] = array[i];
			i--;
		}
		array[i+1] = key;
	}
	return 0;
}


int insertionSort_decreasing(int*array, int length)
{
	int i;
	int j;
	for (j = 1; j < length; j++)
	{	
		int key = array[j];
		i = j-1;
		
		while (i >= 0 &&  array[i] < key) // direction change occurs here
		{
			array[i+1] = array[i];
			i--;
		}
		array[i+1] = key;
	}
	return 0;
}

int printArray(int* array, int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}

