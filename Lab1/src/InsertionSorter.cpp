#include "Sorter.h"

template<size_t N>
class InsertionSorter: public Sorter<int, N>
{
public:
    InsertionSorter() : Sorter<int, N>("Insertion") {}

    void sort(int li[N])
    {
        // Reset the operation counter
        this->reset();

        for (int i = 1; i < N; i++)
        {
            // One operation per outer loop
            this->op();
            // Grab the index of the current element
            int j = i;
            // Iterate down the list, swapping elements until we reach an element which is lower than (or equal to) the current element
            while (j > 0 && li[j - 1] > li[j])
            {
                // At least one operation per inner loop (j > 0)
                this->op();
                // Check for short circuit, if no short circuit, add one more op
                if (j > 0)
                {
                    this->op();
                }
                this->swap(li[j], li[j - 1]);
                j--;
            }
        }
    }
};
