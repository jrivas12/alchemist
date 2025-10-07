#include "InsertionSort.h"

void InsertionSort::sort(std::vector<int>& arr) {
    recursiveInsertionSort(arr, arr.size() - 1);
}

void InsertionSort::recursiveInsertionSort(std::vector<int>& arr, int n) {
    if (n <= 1)
        return;

    recursiveInsertionSort(arr, n - 1);

    int key = arr[n];
    int j = n - 1;

    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}
