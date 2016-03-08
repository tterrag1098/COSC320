#include "CountingSorter.h"

CountingSorter::CountingSorter(Type t, int max) : type(t), max(max), Sorter<int>("Counting"){}

CountingSorter::~CountingSorter(){}

void CountingSorter::sort(int *arr, int size)
{
  switch(type)
  {
    case copy:
      sortCopy(arr, size);
    case inplace:
      sortInPlace(arr, size);
  }
}

void CountingSorter::sortCopy(int* arr, int size)
{
  int *counts = new int[max];
  int *temp = new int[size];
  for (int i = 0; i < max; i++) counts[i] = 0;
  for (int j = 0; j < size; j++)
  {
    counts[arr[j]]++;
  }
  for (int k = 1; k < max; k++)
  {
    counts[k] += counts[k - 1];
  }
  for (int l = size - 1; l >= 0; l--)
  {
    temp[counts[arr[l]]] = arr[l];
    counts[arr[l]]--;
  }
  for (int m = 0; m < size; m++) arr[m] = temp[m];
}

void CountingSorter::sortInPlace(int* arr, int size)
{
  int *counts = new int[max];
  for (int i = 0; i < max; i++) counts[i] = 0;
  for (int j = 0; j < size; j++) counts[arr[j]]++;
  
  int idx = 0;
  for (int k = 0; k < max; k++)
  {
    int m = counts[k];
    while (m > 0)
    {
      arr[idx] = k;
      idx++;
      m--;
    }
  }
}
