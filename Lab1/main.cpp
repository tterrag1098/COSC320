#include <iostream>
#include <list>

#include "src/InsertionSorter.cpp"

template <size_t size>
void fillAscending(int arr[size]) {
    for (int i = 0; i < size;) {
        arr[i] = ++i;
    }
}

template <size_t size>
void fillDescending(int arr[size]) {
    for (int i = size; i > 0;) {
        arr[i - 1] = i--;
    }
}

template <size_t size>
void print(int arr[size]) {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i != size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

template<size_t size>
void sort(int arr[size], Sorter<int, size>& sorter) {
    std::cout << "Before sort:" << std::endl << "\t";
    print<size>(arr);
    sorter.sort(arr);
    std::cout << "After sort:" << std::endl << "\t";
    print<size>(arr);
    std::cout << "Operations: " << sorter.getOpCount() << std::endl;
}

int main()
{
    int arr[20] = {0};
    InsertionSorter<20> sorter;

    fillAscending<20>(arr);
    sort(arr, sorter);

    fillDescending<20>(arr);
    sort(arr, sorter);
}
