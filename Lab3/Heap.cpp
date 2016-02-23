#include "Heap.h"
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

Heap::Heap()
{
    build_heap();
}

Heap::~Heap()
{

}

void Heap::insert(int i)
{
    // First make sure there's room
    if (size >= 100)
    {
        cout << "Heap is full!" << endl;
        return;
    }

    // Add the new element to the next slot
    data[size] = i;
    // Increase the size to include the new element
    size++;
    // Start at the parent of the new element (which is now at size - 1), and iterate up the parents, heapifying each.
    for (int idx = parent(size - 1); idx >= 0; idx = parent(idx))
    {
        heapify(idx);
    }
}

int Heap::getMax()
{
    return data[0];
}

int Heap::extractMax()
{
    int ret = getMax();
    // Set the head to the lowest possible value
    data[0] = INT_MIN;
    // Heapify the head, bringing the new highest value to the top
    heapify(0);
    // Iterate and replace the dummy element with the last element in the heap
    for (int i = 0; i < size; i++)
    {
        if (data[i] == INT_MIN)
        {
            data[i] = data[size - 1];
            data[size - 1] = 0;
        }
    }
    size--;
    return ret;
}

void Heap::print()
{
    print(0, 1);
}

void Heap::print(int i, int indent)
{
    if(i < size)
    {
        if(right(i) < size)
        {
            print(right(i), indent + 4);
        }
        if (indent)
        {
            std::cout << std::setw(indent) << ' ';
        }
        if (right(i) < size) std::cout<< " /\n" << std::setw(indent) << ' ';
        std::cout<< data[i] << "\n ";
        if(left(i) < size)
        {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            print(left(i), indent+4);
        }
    }
}

int Heap::parent(int i)
{
    return i == 0 ? -1 : i % 2 == 0 ? (i - 1) / 2 : i / 2;
}

int Heap::left(int i)
{
    return 2 * i + 1;
}

int Heap::right(int i)
{
    return 2 * i + 2;
}

void Heap::build_heap()
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(i);
    }
}

void Heap::heapify(int i)
{
    int l = left(i), r = right(i);
    int large = i;
    // If the left child is in the heap, check if it is larger
    if (l < size && data[l] > data[large])
    {
        large = l;
    }
    // Next, do the same for the right child
    if (r < size && data[r] > data[large])
    {
        large = r;
    }

    // If a child was larger, swap it with the parent and then heapify that child
    if (large != i)
    {
        int temp = data[i];
        data[i] = data[large];
        data[large] = temp;
        heapify(large);
    }
}

int* Heap::sort()
{
    // Cache the size, as it will be modified by the sort algorithm
    int old_size = size;
    for (int i = size - 1; i > 0; i--)
    {
        // Swap the biggest element with the last element
        int temp = data[0];
        data[0] = data[i];
        data[i] = temp;
        // "Cut off" the last element (which is currently the highest)
        size--;
        // Heapify the new root element to restore the heap property
        heapify(0);
    }
    // Restore the size so that it can be referenced by caller
    size = old_size;
    return data;
}

int Heap::getSize()
{
    return size;
}
