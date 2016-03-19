#include "CountingSorter.h"

CountingSorter::CountingSorter(Type t, int max) : type(t), max(max), Sorter<int>("Counting")
{
    reset();
}

CountingSorter::~CountingSorter(){}

void CountingSorter::sort(int *arr, int size)
{
  switch(type)
  {
    case copy:
      sortCopy(arr, size);
      break;
    case inplace:
      sortInPlace(arr, size);
      break;
  }
}

void CountingSorter::sortCopy(int* arr, int size)
{
  int *counts = new int[max];
  int *temp = new int[size];
  for (int i = 0; op(), i < max; i++) counts[i] = 0;
  for (int j = 0; op(), j < size; j++)
  {
    counts[arr[j]]++;
  }
  for (int k = 1; op(), k < max; k++)
  {
    counts[k] += counts[k - 1];
  }
  for (int l = size - 1; op(), l >= 0; l--)
  {
    temp[counts[arr[l]] - 1] = arr[l];
    counts[arr[l]]--;
  }
  for (int m = 0; op(), m < size; m++) arr[m] = temp[m];
}

void CountingSorter::sortInPlace(int* arr, int size)
{
  int counts[max];
  for (int i = 0; op(), i < max; i++) counts[i] = 0;
  for (int j = 0; op(), j < size; j++) counts[arr[j]]++;

  int idx = 0;
  for (int k = 0; op(), k < max; k++)
  {
    int m = counts[k];
    while (op(), m > 0)
    {
      arr[idx] = k;
      idx++;
      m--;
    }
  }
}
