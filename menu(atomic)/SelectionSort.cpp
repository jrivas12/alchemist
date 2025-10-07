#include "SelectionSort.h"
using namespace std;

void SelectionSort::sort(vector<int>& arr) {
    recursiveSelectionSort(arr, arr.size());
}

void SelectionSort::recursiveSelectionSort(vector<int>& arr, int n) {
    if (n <= 1)
        return;

    int minIndex = findMinIndex(arr, 0, n - 1);
    swap(arr[minIndex], arr[n - 1]);

    recursiveSelectionSort(arr, n - 1);
}

int SelectionSort::findMinIndex(vector<int>& arr, int start, int end) {
    int minIndex = start;
    for (int i = start + 1; i <= end; ++i) {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }
    return minIndex;
}
