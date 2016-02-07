#include "Sorter.h"
#include <list>

template<size_t N>
class InsertionSorter: public Sorter<int, N>
{
public:
    void sort(int li[N]) {
        *(this->opCount) = 0;
        for (int i = 1; i < N; i++) {
            int j = i;
            while (j --> 0 && li[j - 1] > li[j]) {
                (*(this->opCount))++;
                int tmp = li[j];
                li[j] = li[j - 1];
                li[j - 1] = tmp;
            }
        }
    }
};
