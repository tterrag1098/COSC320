#include "Sorter.h"

template<size_t N>
class InsertionSorter: public Sorter<int, N>
{
public:
    void sort(int li[N])
    {
        this->reset();
        for (int i = 1; i < N; i++)
        {
            int j = i;
            this->op(), this->op();
            while (j > 0 && li[j - 1] > li[j])
            {
                this->swap(li[j], li[j - 1]);
                j--;
            }
        }
    }
};
