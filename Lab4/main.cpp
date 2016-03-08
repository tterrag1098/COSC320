#include <iostream>
#include <fstream>
#include <list>
#include <stdlib.h>

#include "QuickSorter.h"
#include "CountingSorter.h"

#define end1 std::endl
#define end2 std::endl << std::endl
#define section "==============================================="

// Fills a given array of with random integers ranging from 1 to size
void fillRandom(int *arr, int size, int min, int max)
{
    srand(8);
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % (max - min)) + min;
    }
}

static std::ofstream out;

// Prints an array to the console
void print(int *arr, int size)
{
    out << "[";
    for (int i = 0; i < size; i++)
    {
        out << arr[i];
        if (i != size - 1)
        {
            out << ", ";
        }
    }
    out << "]" << end1;
}

// Sorts an array, using a given sorter, and prints out the intermediate steps
void sort(int *arr, int size, Sorter<int>* sorter)
{
    out << "\tBefore sort: ";
    print(arr, size);
    sorter->sort(arr, size);
    out << "\tAfter sort: ";
    print(arr, size);
    out << "\tOperations: " << sorter->getOpCount() << end2;
}

// Tests a sorter, printing out its name/size, and the type of each test
void test(Sorter<int>* sorter, int size, int min, int max)
{
    int *arr = new int[size];

    out << sorter->getName() << " sort, with " << size << " elements:" << end2;

    out << "Random order:" << end1;
    fillRandom(arr, size, min, max);
    sort(arr, size, sorter);

    out << section << end2;
    delete sorter;
}

int main()
{
    out.open("output.txt");
    out << section << end2;

    test(new QuickSorter(one), 30, 1, 100);
    test(new QuickSorter(two), 30, 1, 100);
    
    test(new CountingSorter(copy, 100), 30, 1, 100);
    test(new CountingSorter(inplace, 100), 30, 1, 100);

    std::cout << "See output.txt for sorting information" << std::endl;
}
