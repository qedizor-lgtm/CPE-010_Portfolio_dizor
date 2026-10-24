#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <algorithm>

template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        for (size_t j = i + 1; j < arrSize; j++) {
            if (arr[j] > arr[i]) {
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

template <typename T> 
int Routine_Smallest(T A[], int K, const int arrSize);

template <typename T>
void selectionSort(T arr[], const int N) {
    int POS, temp, pass = 0;
    for (int i = 0; i < N - 1; i++) {
        POS = Routine_Smallest(arr, i, N);
        temp = arr[i];

        arr[i] = arr[POS];
        arr[POS] = temp;
        
        pass++;
    }
}

template <typename T>
int Routine_Smallest(T A[], int K, const int arrSize) {
    int position;
    T smallestElem = A[K];
    position = K;
    
    for (int j = K + 1; j < arrSize; j++) {
        if (A[j] < smallestElem) {
            smallestElem = A[j];
            position = j;
        }
    }
    return position;
}

#endif 

