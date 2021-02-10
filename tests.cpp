#include "main.hpp"
#include <iostream>

extern SearchResult FindMinValue(ArrayPointer array);


TestTableEntry TestTable[] = {
    {SearchResult(1,  0), {1, 2, 3, 4, 5}},
    {SearchResult(3,  2), {95, 23, 3, 24, 15}},
    {SearchResult(31, 0), {31, 82, 53, 43, 52}},
    {SearchResult(25, 4), {214, 472, 2343, 8764, 25}},
    {SearchResult(8,  1), {714, 8, 33, 45, 85}}
};

void PrintArray(ArrayPointer array){
    std::cout << '{';
    for(int i = 0; ; i++){
        std::cout << array.Pointer[i];
        if(i == array.Size - 1)
            break;
        
        std::cout << ", ";
    }
    std::cout << '}' << std::endl;
}

void RunTests(){
    int tests_count = sizeof(TestTable)/sizeof(TestTableEntry);

    bool failed = false;

    for(int i = 0; i<tests_count; i++){
        std::cout << "Running Test [" << i + 1 << "]" << std::endl;

        ArrayPointer array;
        array.Pointer = TestTable[i].Data.data();
        array.Size = TestTable[i].Data.size();

        SearchResult result = FindMinValue(array);
        SearchResult expected = TestTable[i].ExpectedResult;

        if(result.Value != expected.Value || result.Index != expected.Index){
            failed = true;
            std::cout << "Failed" << std::endl;
            PrintArray(array);
            std::cout << "Value: " << result.Value << ", Expected: " << expected.Value << std::endl;
            std::cout << "Index: " << result.Index << ", Expected: " << expected.Index << std::endl;
        }else{
            std::cout << "Success" << std::endl;
        }
    }
    std::cout << std::endl;
    if(failed){
        std::cout << "Exiting due to test failure" << std::endl;
        std::exit(0);
    }
}