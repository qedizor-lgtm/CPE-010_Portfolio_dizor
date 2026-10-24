#ifndef SORTING_H
#define SORTING_H

template <typename T>
void insertionSort(T arr[], const int N) {
    for (int K = 1; K < N; K++) {
        T temp = arr[K];
        int J = K - 1;
        while (J >= 0 && temp < arr[J]) {
            arr[J + 1] = arr[J];
            J--;
        }
        arr[J + 1] = temp;
    }
}

#endif 

