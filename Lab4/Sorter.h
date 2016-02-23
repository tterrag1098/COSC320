#ifndef SORTER_H
#define SORTER_H

#include "stddef.h"
#include <string>

template <typename T, size_t N>
class Sorter
{
public:
    Sorter(std::string name) : name(name){};
    virtual ~Sorter(){};
    virtual void sort(T li[N]) = 0;
    std::string getName() { return name; };
protected:
    void swap(T& a, T& b)
    {
        T temp = a;
        a = b;
        b = temp;
    }
private:
    std::string name;
};

#endif // SORTER_H
