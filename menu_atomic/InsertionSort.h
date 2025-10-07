#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <vector>

class InsertionSort {
public:
    static void sort(std::vector<int>& arr);
    
private:
    static void recursiveInsertionSort(std::vector<int>& arr, int n);
};

#endif