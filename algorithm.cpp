#include "main.hpp"

SearchResult FindMinValue(ArrayPointer array){

    int min = array.Pointer[0], element = 0;
    for (int i = 0; i < array.Size; i++)
    {
        if (array.Pointer[i] < min)
        {
            min = array.Pointer[i];
            element = i;
        }
    }
    SearchResult result;

    result.Value = min;
    result.Index = element;
    return result;
}