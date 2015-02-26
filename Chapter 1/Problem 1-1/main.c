#include <stdio.h>

int inverseFactorial(long long unsigned int);

// I just could never get this to completely work... gcc seems to dislike big numbers.

int main()
{
	long long unsigned int inputs[128] = {1000000ULL, 60000000ULL, 3600000000ULL, 86400000000ULL, 2592000000000ULL, 31104000000000ULL, 3110400000000000ULL, 0};


	
	int i;
	int a;
	for (i = 0; (a = inputs[i]); i++)
	{
		printf("%i ", inverseFactorial(a));
	}
	
	return 0;
}


int inverseFactorial(long long unsigned n)
{
	int i;
	for (i = 2; n > i; i++)
	{
		n /= i;
	}
	
	return i-1;
}