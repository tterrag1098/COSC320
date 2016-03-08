#ifndef QUICK_SORTER_H
#define QUICK_SORTER_H

#include "Sorter.h"
#include <stddef.h>

enum Partition { one, two };

class QuickSorter : public Sorter<int>
{
public:
  QuickSorter (Partition p);
  ~QuickSorter ();
  void sort(int *arr, int size) override;
private:
  int size;
  
  void sort(int *arr, int p, int r);
  int partition(int *arr, int p, int r);
  void print(int *arr, int size);
  Partition type;
};

#endif