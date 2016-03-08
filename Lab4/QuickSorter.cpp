#include "QuickSorter.h"
#include <iostream>

QuickSorter::QuickSorter(Partition p) : type(p), Sorter<int>("Quicksort"){}

QuickSorter::~QuickSorter()
{

}

void QuickSorter::sort(int *arr, int size)
{
    this->size = size;
    sort(arr, 0, size - 1);
}

void QuickSorter::sort(int *arr, int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
	sort(arr, p, q);
	sort(arr, q + 1, r);
    }
}

int QuickSorter::partition(int *arr, int p, int r)
{
  switch(type)
  {
    int pivot, i, j;
    case one:
      pivot = arr[r];
      i = p - 1;
      for (j = p; op(), j < r - 1; j++)
      {
	  op();
	  if (arr[j] <= pivot)
	  {
	      i++;
	      swap(arr[i], arr[j]);
	  }
      }
      swap(arr[i + 1], arr[r]);
      return i + 1;
    case two:
      pivot = arr[p];
      i = p - 1;
      j = r + 1;
      for(;;)
      {
	j--;
	while (arr[j] > pivot) j--;

	i++;
	while (arr[i] < pivot) i++;
	
	if (i < j) swap(arr[i], arr[j]);
	else return j;
      }
  }
}

void QuickSorter::print(int* arr, int size)
{
    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i != size - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

