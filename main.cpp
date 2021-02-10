#include <stdio.h>
#include "main.hpp"

extern ArrayPointer ConsoleInput();
extern ArrayPointer FileInput();
extern ArrayPointer RandomInput();

extern SearchResult FindMinValue(ArrayPointer array);

extern void RunTests();

int main(){
    RunTests();

    do{
        puts("<=== Enter Input Type ===>");
        puts("1) Console Input");
        puts("2) File Input");
        puts("3) Random Input");

        char option = getchar();
        if(getchar() != '\n'){
            puts("Wrong option");
            continue;
        }

        ArrayPointer array;
    //comment
        switch (option) {
        case '1':
            array = ConsoleInput();
            break;
        case '2':
            array = FileInput();
            break;
        case '3':
            array = RandomInput();
            break;
        default:
            puts("Wrong option");
            continue;
        }

        SearchResult result = FindMinValue(array);

        printf("Min value is: %i, with index: %i", result.Value, result.Index);
    }while(getchar() == '\n');
}