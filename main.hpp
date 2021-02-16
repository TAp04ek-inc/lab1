#ifndef MAIN_HPP
#define MAIN_HPP

#include <vector>

struct ArrayPointer{
    int *Pointer;
    int Size;
};

struct SearchResult{
    int Value;
    int Index;

    SearchResult():
        Value(0),
        Index(-1)
    {}

    SearchResult(int value, int index):
        Value(value),
        Index(index)
    {}
};

struct TestTableEntry{
    SearchResult ExpectedResult;
    std::vector<int> Data;
};

#endif
