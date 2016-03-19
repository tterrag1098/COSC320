#ifndef INSERTIONSORTER_H_INCLUDED
#define INSERTIONSORTER_H_INCLUDED

#include "Sorter.h"

class InsertionSorter : public Sorter<int>
{
public:
    InsertionSorter ();
    ~InsertionSorter ();
    void sort(int *arr, int size) override;
};

#endif // INSERTIONSORTER_H_INCLUDED
