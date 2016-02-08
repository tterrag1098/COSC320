#include <Sorter.h>

template<size_t N>
class BubbleSorter : public Sorter<int, N>
{
public:
    BubbleSorter() : Sorter<int, N>("Bubble") {}
    void sort(int li[N])
    {
        // Reset the operation counter
        this->reset();

        // Each pass guarantees that the last element is sorted, so we decrement the max by 1 each pass
        for (int max = N - 1; max > 0; max--)
        {
            // One operation per outer loop
            this->op();
            // Iterate up to the max
            for (int i = 0; i <= max; i++)
            {
                // One operation per inner loop
                this->op();
                // If this value and the next need to be swapped, swap them
                if (li[i] > li[i + 1])
                {
                    this->swap(li[i], li[i + 1]);
                }
                // One operation from if block
                this->op();
            }
        }
    }
};
