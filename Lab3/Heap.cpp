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
    if (size >= 100)
    {
        cout << "Heap is full!" << endl;
        return;
    }

    data[size] = i;
    size++;
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
    data[0] = INT_MIN;
    heapify(0);
    for (int i = 0; i < size; i++)
    {
        if (data[i] == INT_MIN)
        {
            data[i] = data[size - 1];
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
    if (l < size && data[l] > data[large])
    {
        large = l;
    }
    if (r < size && data[r] > data[large])
    {
        large = r;
    }

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
    int old_size = size;
    for (int i = size - 1; i > 0; i--)
    {
        int temp = data[0];
        data[0] = data[i];
        data[i] = temp;
        size--;
        heapify(0);
    }
    size = old_size;
    return data;
}

int Heap::getSize()
{
    return size;
}
