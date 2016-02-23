#include "Sorter.h"
#include <stddef.h>

enum Partition { recursive, iterative };

template <size_t N>
class QuickSorter : public Sorter<int, N>
{
public:
  QuickSorter<N> (Partition p) : partition(p), Sorter<int, N>("Quicksort"){}
  void sort(int arr[N]) override;
private:
  Partition partition;
};