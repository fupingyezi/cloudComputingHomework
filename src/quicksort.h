#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

void quicksort(std::vector<int>& arr, int left, int right);
int partition(std::vector<int>& arr, int left, int right);
void printArray(const std::vector<int>& arr);

#endif
