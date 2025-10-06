#ifndef ARRAYSTATS_H
#define ARRAYSTATS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
using namespace std;

template<typename T>
class ArrayStats {
private:
    T* array;
    int size;

public:
    ArrayStats(int size, T value) : size(size) {
        if (size <= 0) {
            throw invalid_argument("Size must be greater than 0");
        }
        array = new T[size];
        for (int i = 0; i < size; ++i) {
            array[i] = value;
        }
    }
    T findMax() {
        T max = array[0];
        for (int i = 1; i < size; ++i) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        return max;
    }
    T findMin() {
        T min = array[0];
        for (int i = 1; i < size; ++i) {
            if (array[i] < min) {
                min = array[i];
            }
        }
        return min;
    }
    void randomizeValues() {
        srand(time(0));
        for (int i = 0; i < size; ++i) {
            array[i] = static_cast<T>(rand() % 100);
        }
    }
    T* getArray() const {
        return array;
    }
    ~ArrayStats() {
        delete[] array;
    }
};

#endif
