#include "main.hpp"
#include <stdio.h>
#include <ctime>

ArrayPointer RandomInput()
{
	ArrayPointer array;
	puts("Enter size of the array: ");
	scanf_s("%d", &array.Size);

	array.Pointer = new int(array.Size);
	//array.Pointer = (int*)malloc(array.Size * sizeof(int));

	printf("Your array: { ");
	unsigned value = unsigned(std::time(0)); //начало последовательности
	for (int i = 0; i < array.Size; ++i)
	{
		value = (value * 42059 + 2281337) % 1000 - 223; //числа ,,от фонаря,, для магии
		array.Pointer[i] = value;
		printf("%d, ", array.Pointer[i]);
	}
	printf("}");
		
	return array;	
}