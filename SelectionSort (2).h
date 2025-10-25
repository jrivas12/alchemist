#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <vector>
using namespace std;

class SelectionSort {
public:
    static void sort(vector<int>& arr);
    
private:
    static void recursiveSelectionSort(vector<int>& arr, int n);
    static int findMinIndex(vector<int>& arr, int start, int end);
};

#endif 
