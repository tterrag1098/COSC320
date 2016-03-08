#ifndef SORTER_H
#define SORTER_H

#include "stddef.h"
#include <string>

template <typename T>
class Sorter
{
public:
    Sorter(std::string name) : name(name){};
    virtual ~Sorter(){};
    virtual void sort(T *arr, int size) = 0;
    int getOpCount() { return opCount; }
    std::string getName() { return name; };
protected:
    void reset() { opCount = 0; }
    void op() { opCount++; }
    void swap(T& a, T& b)
    {
        T temp = a;
        a = b;
        b = temp;
    }
private:
    int opCount;
    std::string name;
};

#endif // SORTER_H
