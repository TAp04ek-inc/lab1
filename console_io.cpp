#include "main.hpp"
#include <stdio.h>

ArrayPointer ConsoleInput(){
    ArrayPointer array;
    puts("Enter size of array");
    scanf("%d", &array.Size);
    array.Pointer = new int[array.Size];
    for (int i = 0; i < array.Size; ++i) {
        printf("Enter element[%d]", i + 1);
        scanf("%d", &array.Pointer[i]);
    }
    return array;
}