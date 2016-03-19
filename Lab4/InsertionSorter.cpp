#include "Sorter.h"

#include "InsertionSorter.h"

InsertionSorter::InsertionSorter() : Sorter("Insertion") {}

InsertionSorter::~InsertionSorter(){}

void InsertionSorter::sort(int *arr, int size)
{
    // Reset the operation counter
    this->reset();

    for (int i = 1; i < size; i++)
    {
        // One operation per outer loop
        this->op();
        // Grab the index of the current element
        int j = i;
        // Iterate down the list, swapping elements until we reach an element which is lower than (or equal to) the current element
        while (j > 0 && arr[j - 1] > arr[j])
        {
            // At least one operation per inner loop (j > 0)
            this->op();
            // Check for short circuit, if no short circuit, add one more op
            if (j > 0)
            {
                this->op();
            }
            this->swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}
