#include <Sorter.h>

template<size_t N>
class SelectionSorter : public Sorter<int, N>
{
public:
    SelectionSorter() : Sorter<int, N>("Selection") {}
    void sort(int li[N])
    {
        // Reset the operation counter
        this->reset();

        // Iterate through the array, ignoring the last element as this is our final compare target
        for (int i = 0; i < N - 1; i++)
        {
            // The minimum value's index starts at the current one, everything at or below this index must be sorted
            int min = i;
            for (int j = min + 1; j < N; j++)
            {
                // Iterate up the list, looking for the smallest value, then storing it
                if (li[j] < li[min])
                {
                    min = j;
                }
                this->op(), this->op(); // comparison = 2 ops
            }
            // Swap the found min value with the current index
            if (min != i)
            {
                this->swap(li[i], li[min]);
            }
        }
    }
};
