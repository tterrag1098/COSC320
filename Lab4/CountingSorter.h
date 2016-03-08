#ifndef COUNTING_SORTER_H
#define COUNTING_SORTER_H

#include "Sorter.h"

enum Type { copy, inplace };

class CountingSorter : public Sorter<int>
{
  public:
  CountingSorter (Type t, int max);
  ~CountingSorter ();
  void sort(int *arr, int size) override;
private:
  void sortCopy(int *arr, int size);
  void sortInPlace(int *arr, int size);
  int max;
  Type type;
};

#endif