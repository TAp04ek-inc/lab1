#include "main.hpp"
#include <stdio.h>
#include <random>
ArrayPointer RandomInput()
{
	ArrayPointer array;
	printf("\nEnter size of the array: ");
	scanf("%d", &array.Size);

	array.Pointer = new int(array.Size);

	int MIN;
	printf("\nEnter the range of values.");
	do 
	{
		printf("\nMIN [%d; %d): ", INT_MIN, INT_MAX);
		scanf("%d", &MIN);
	} while (!(MIN >= INT_MIN && MIN < INT_MAX));
	
	int MAX;
	do
	{
		printf("\nMAX (%d; %d]: ", MIN, INT_MAX);
		scanf("%d", &MAX);
	} while (!(MAX > MIN && MAX <= INT_MAX));
	
	printf("\nYour array: { ");

	std::random_device random;
	for (int i = 0; i < array.Size; ++i)
	{
		std::default_random_engine element(random());
		std::uniform_int_distribution<int> uniform_dist(MIN, MAX);
		array.Pointer[i] = uniform_dist(element);
		printf("%d, ", array.Pointer[i]); 
	}
	printf("}\n\n");
		
	return array;	
}