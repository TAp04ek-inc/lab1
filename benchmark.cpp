#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <random>
#include <iomanip>
#include "main.hpp"
#include "clock.hpp"

struct BenchmarkEntry{
    Time SearchTime;
    int ArraySize;
};

extern SearchResult FindMinValue(ArrayPointer array);

void PrintEntry(std::fstream &stream, BenchmarkEntry entry){
    stream << std::fixed << entry.SearchTime.AsNanoseconds() << ',' << entry.ArraySize << std::endl << std::flush;
}

std::time_t c_time = std::time(nullptr);
std::tm *current_time = std::localtime(&c_time);

const int BenchmarkBegin = 0;
const int BenchmarkEnd   = 200000;
const int BenchmarkStep  = 2000;

void RunBenchmark(){
    std::cout << "Running Benchmarks" << std::endl;

    std::string filename = "benchmark_" + std::to_string(current_time->tm_hour) + "_" + std::to_string(current_time->tm_min) + "_" + std::to_string(current_time->tm_sec) + ".txt";
    std::fstream out_file;
    out_file.open(filename, std::ios::out);

    if(!out_file.is_open()){
        std::cout << "Benchmark Failed" << std::endl;
        return;
    }

    std::random_device random;
    for(int i = BenchmarkBegin; i<=BenchmarkEnd; i+= BenchmarkStep){
        std::cout << float(i)*100/float(BenchmarkEnd-BenchmarkBegin) << "%\n";

        ArrayPointer array;
        array.Size = i;
        array.Pointer = new int[array.Size];

        for (int j = 0; j < array.Size; ++j){
            std::default_random_engine element(random());
            std::uniform_int_distribution<int> uniform_dist(-100000, 100000);
            array.Pointer[j] = uniform_dist(element);
        }

        Clock clock;

        SearchResult result = FindMinValue(array);

        BenchmarkEntry entry{clock.GetElapsedTime(), array.Size};
        PrintEntry(out_file, entry);

        delete[] array.Pointer;
    }
    //system(std::string("../graph.py " + filename).c_str()); // For unix users XD

}