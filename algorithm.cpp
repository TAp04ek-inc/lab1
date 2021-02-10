#include "main.hpp"

SearchResult FindMinValue(ArrayPointer array){

    SearchResult result;

    result.Value = array.Pointer[0], result.Index = 0;
    for (int i = 0; i < array.Size; i++)
    {
        if (array.Pointer[i] < result.Value)
        {
            result.Value = array.Pointer[i];
            result.Index = i;
        }
    }

    return result;
}