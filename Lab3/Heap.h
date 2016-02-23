#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include <stddef.h>

class Heap
{
public:
    Heap();
    virtual ~Heap();
    void insert(int i);
    int extractMax();
    int getMax();
    void print();
    int* sort();
    int getSize();
private:
    int data[100] = {4, 12, 3, 19, 23, 5, 32, 11, 2, 24};
    int size = 10;

    int parent(int i);
    int left(int i);
    int right(int i);
    void heapify(int i);
    void build_heap();
    void print(int i, int indent = 0);
};

#endif // HEAP_H_INCLUDED
