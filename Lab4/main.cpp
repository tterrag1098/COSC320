#include <iostream>
#include <fstream>
#include <list>
#include <stdlib.h>

#include "QuickSorter.h"

#define end1 std::endl
#define end2 std::endl << std::endl
#define section "==============================================="

// Fills a given array of with random integers ranging from 1 to 100
template <size_t size>
void fillRandom(int arr[size])
{
    srand(8);
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 100) + 1;
    }
}

static std::ofstream out;

// Prints an array to the console
template <size_t size>
void print(int arr[size])
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
template<size_t size>
void sort(int arr[size], Sorter<int, size>* sorter)
{
    out << "\tBefore sort: ";
    print<size>(arr);
    sorter->sort(arr);
    out << "\tAfter sort: ";
    print<size>(arr);
}

// Tests a sorter, printing out its name/size, and the type of each test
template<size_t size>
void test(Sorter<int, size>* sorter)
{
    int arr[size] = {0};

    out << sorter->getName() << " sort, with " << size << " elements:" << end2;

    fillRandom<size>(arr);
    sort(arr, sorter);

    out << section << end2;
    delete sorter;
}

int main()
{
    out.open("output.txt");
    out << section << end2;

    test(new QuickSorter<30>(iterative));
    
    std::cout << "See output.txt for sorting information" << std::endl;
}
