#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "InsertionSort.h"
#include "SelectionSort.h"
using namespace std;

void printArray(const vector<int>& arr);
vector<int>::iterator findMinIndex(vector<int>::iterator start, vector<int>::iterator end);
void selectionSortRecursive(vector<int>& arr, vector<int>::iterator start, vector<int>::iterator end);

int main() {
    vector<int> arr1 = {5, 3, 8, 1, 4};
    vector<int> arr2 = {5, 3, 8, 1, 4};

    cout << "\033[1;35mSorting Algorithms\n";
    cout << "\033[1;33m" << setw(15) << "\nOriginal array:\n" << setw(20) << "\033[0m" << endl;
    cout << setw(15);
    printArray(arr1);
    cout << "\033[1;33m" << setw(15) << "\nInsertion Sort:\n" << setw(20) << "\033[0m" << endl;
    InsertionSort::sort(arr1);
    printArray(arr1);
    cout << "\033[1;33m" << setw(15) << "\nSelection Sort:\n" << setw(20) << "\033[0m" << endl;
    SelectionSort::sort(arr2);
    printArray(arr2);

    arr1.push_back(10); 
    arr2.erase(arr2.begin() + 1);
    reverse(arr1.begin(), arr1.end()); 

    cout << "\n------------Simulating modifications------------\n";
    cout << "Array 1 after insertion: ";
    printArray(arr1);
    cout << "Array 2 after deletion: ";
    printArray(arr2);
    cout << "------------------------------------------------\n";

    InsertionSort::sort(arr1);
    SelectionSort::sort(arr2);

    cout << "\nSorted array:\n" << setw(20) << endl;
    printArray(arr1);
    printArray(arr2);
    
    srand(time(nullptr));

    const int SIZE = 20;
    const int MAX_RANDOM_VALUE = 100;
    vector<int> arr(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % MAX_RANDOM_VALUE;
    }

    cout << "\nUnsorted array:" << endl;
    printArray(arr);

    selectionSortRecursive(arr, arr.begin(), arr.end());

    cout << "\nSorted array:" << endl;
    printArray(arr);
    printArray(arr1);
    printArray(arr2);

    return 0;
}
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << "\033[1;36m" << setw(4) << num << "\033[0m";
    }
    cout << endl;
}

vector<int>::iterator findMinIndex(vector<int>::iterator start, vector<int>::iterator end) {
    return min_element(start, end);
}

void selectionSortRecursive(vector<int>& arr, vector<int>::iterator start, vector<int>::iterator end) {
    if (start == end) {
        return;
    }
    auto minIndex = findMinIndex(start, end);
    if (minIndex != start) {
        iter_swap(minIndex, start);
    }
    selectionSortRecursive(arr, start + 1, end);
}
