#include <iostream>
#include <fstream>
#include <list>
#include <stdlib.h>

#include "src/InsertionSorter.cpp"
#include "src/SelectionSorter.cpp"
#include "src/BubbleSorter.cpp"
#include "src/MergeSorter.cpp"

#define end1 std::endl
#define end2 std::endl << std::endl

// Fills a given array with ascending integers from 1 to size
template <size_t size>
void fillAscending(int arr[size])
{
    for (int i = 0; i < size;)
    {
        arr[i] = ++i;
    }
}

// Fills a given array with descending integers from size to 1
template <size_t size>
void fillDescending(int arr[size])
{
    for (int i = 0; i < size;)
    {
        arr[i] = size - i++;
    }
}

// Fills a given array of with random integers ranging from 1 to size
template <size_t size>
void fillRandom(int arr[size])
{
    srand(8);
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % size) + 1;
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
    out << "Before sort:" << end1 << "\t";
    print<size>(arr);
    sorter->sort(arr);
    out << "After sort:" << end1 << "\t";
    print<size>(arr);
    out << "Operations: " << sorter->getOpCount() << end2;
}

// Tests a sorter, printing out its name/size, and the type of each test
template<size_t size>
void test(Sorter<int, size>* sorter)
{
    int arr[size] = {0};

    out << sorter->getName() << " sort, with " << size << " elements:" << end1;

    out << "Ascending order:" << end2;
    fillAscending<size>(arr);
    sort(arr, sorter);

    out << "Descending order:" << end2;
    fillDescending<size>(arr);
    sort(arr, sorter);

    out << "Random order:" << end2;
    fillRandom<size>(arr);
    sort(arr, sorter);

    delete sorter;
}

int main()
{
    out.open("output.txt");

    test(new InsertionSorter<20>());
    test(new InsertionSorter<100>());

    test(new SelectionSorter<20>());
    test(new SelectionSorter<100>());

    test(new BubbleSorter<20>());
    test(new BubbleSorter<100>());

    test(new MergeSorter<20>());
    test(new MergeSorter<100>());

    std::cout << "See output.txt for sorting information" << std::endl;
}
