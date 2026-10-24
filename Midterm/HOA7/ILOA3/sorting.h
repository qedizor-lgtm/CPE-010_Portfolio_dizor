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
    int POS, pass = 0;
    T temp;
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
    int position = K;
    T smallestElem = A[K];
    for (int j = K + 1; j < arrSize; j++) {
        if (A[j] < smallestElem) {
            smallestElem = A[j];
            position = j;
        }
    }
    return position;
}

template <typename T>
void insertionSort(T arr[], const int N) {
    int K = 1, J; 
    T temp; 
    
    while (K < N) {

        temp = arr[K];

        J = K - 1;
        
        while (J >= 0 && temp <= arr[J]) {

            arr[J + 1] = arr[J];

            J--;

        }
        arr[J + 1] = temp;
        K++;
    }

}

#endif

