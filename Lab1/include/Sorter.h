#ifndef SORTER_H
#define SORTER_H

#include "stddef.h"

template <typename T, size_t N>
class Sorter
{
public:
    Sorter();
    virtual ~Sorter();
    virtual void sort(T li[N]) = 0;
    int getOpCount() { return opCount; }
protected:
    int opCount;
};

#endif // SORTER_H
