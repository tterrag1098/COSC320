#ifndef BUCKETSORTER_H_INCLUDED
#define BUCKETSORTER_H_INCLUDED

#include "Sorter.h"

class BucketSorter : public Sorter<int>
{
    friend class Node;

public:
    BucketSorter (int max);
    ~BucketSorter ();
    void sort(int *arr, int size) override;
private:
    int max;
};

class Node
{
    friend class BucketSorter;

public:
    Node(int value) : value(value){};
    Node();
    ~Node();
    int sort(BucketSorter *sorter, int *arr, int off);
private:
    int value;
    Node *next = NULL;
    Node *prev = NULL;
};

#endif // BUCKETSORTER_H_INCLUDED
