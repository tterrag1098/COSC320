#include <iostream>
#include <list>

#include "src/InsertionSorter.cpp"

template <size_t size>
void fillArrayAscending(int arr[size]) {
    int ret[size], i;
    for (i = 0; i < size;) {
        ret[i] = ++i;
    }
}

int main()
{
    int thru20[20];
    fillArrayAscending<20>(thru20);

    InsertionSorter<20> sorter;

    sorter.sort(thru20);

    std::cout << "Operations: " << sorter.getOpCount() << std::endl;
}
