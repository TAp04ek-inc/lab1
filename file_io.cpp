#include "main.hpp"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

ArrayPointer FileInput(){
    ArrayPointer array;
    string numbers[20];
    puts("Enter your filename");
    string fileName;
    ifstream File;
    for(;;){
        cin >> fileName;
        File.open(fileName);
        if(File.is_open())
            break;
        else {
            puts("Wrong filename, try again!");
            continue;
        }
    }
    puts("How are your numbers written?\n"
         "1 - {1,2,3,4...}\n"
         "2 - {1;2;3;4...}\n"
         "3 - One number on each string");
    int choice;
    char separator;
    cin >> choice;
    switch (choice) {
        case 1:
            separator = ',';
            break;
        case 2:
            separator = ';';
            break;
        case 3:
            separator = '\n';
            break;
        default:
            separator = ',';
            puts("Invalid choice, your separator will be automatically set to "",""");
            break;
    }
    int i = 0;
    while (getline(File, numbers[i], separator)) {
        array.Size = i++;
    }
    array.Pointer = new int[array.Size];
    for (int j = 0; j < array.Size; ++j) {
        array.Pointer[j] = stoi(numbers[j]);
    }

    File.close();
    return array;
}