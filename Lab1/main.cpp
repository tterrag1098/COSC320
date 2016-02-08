#include <iostream>
#include <list>
#include <stdlib.h>

#include "src/InsertionSorter.cpp"
#include "src/SelectionSorter.cpp"
#include "src/BubbleSorter.cpp"
#include "src/MergeSorter.cpp"

#define end1 std::endl
#define end2 std::endl << std::endl

template <size_t size>
void fillAscending(int arr[size])
{
    for (int i = 0; i < size;)
    {
        arr[i] = ++i;
    }
}

template <size_t size>
void fillDescending(int arr[size])
{
    for (int i = 0; i < size;)
    {
        arr[i] = size - i++;
    }
}

template <size_t size>
void fillRandom(int arr[size])
{
    srand(8);
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % size) + 1;
    }
}

template <size_t size>
void print(int arr[size])
{
    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i != size - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << end1;
}

template<size_t size>
void sort(int arr[size], Sorter<int, size>& sorter)
{
    std::cout << "Before sort:" << end1 << "\t";
    print<size>(arr);
    sorter.sort(arr);
    std::cout << "After sort:" << end1 << "\t";
    print<size>(arr);
    std::cout << "Operations: " << sorter.getOpCount() << end2;
}

template<size_t size>
void test(std::string name, Sorter<int, size>& sorter)
{
    int arr[size] = {0};

    std::cout << name << " sort, with " << size << " elements:" << end1;

    std::cout << "Ascending order:" << end2;
    fillAscending<size>(arr);
    sort(arr, sorter);

    std::cout << "Descending order:" << end2;
    fillDescending<size>(arr);
    sort(arr, sorter);

    std::cout << "Random order:" << end2;
    fillRandom<size>(arr);
    sort(arr, sorter);
}

int main()
{
    InsertionSorter<20> insertion20;
    InsertionSorter<100> insertion100;

    test("Insertion", insertion20);
    test("Insertion", insertion100);

    SelectionSorter<20> selection20;
    SelectionSorter<100> selection100;
    test("Selection", selection20);
    test("Selection", selection100);

    BubbleSorter<20> bubble20;
    BubbleSorter<100> bubble100;

    test("Bubble", bubble20);
    test("Bubble", bubble100);

    MergeSorter<20> merge20;
    MergeSorter<100> merge100;

    test("Merge", merge20);
    test("Merge", merge100);
}
