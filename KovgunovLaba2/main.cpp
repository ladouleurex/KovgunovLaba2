#include "structs.h"
#include "sorts.h"
#include "tests.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    setlocale(LC_ALL, "Rus");

    std::string inputFile = "input_10000.txt";
    std::string outputHeap = "heap_output.txt";
    std::string outputInsert = "insert_output.txt";

    std::vector<Key> data;
    readInput(inputFile, data);

    std::vector<Key> dataHeap = data;
    std::vector<Key> dataInsert = data;

    long long t1 = time([&]() { heapSort(dataHeap); });
    writeOutput(outputHeap, dataHeap, t1);

    long long t2 = time([&]() { insertionSort(dataInsert); });
    writeOutput(outputInsert, dataInsert, t2);

    std::cout << "Heap sort time: " << t1 << " ms\n";
    std::cout << "Insertion sort time: " << t2 << " ms\n";

    return 0;
}