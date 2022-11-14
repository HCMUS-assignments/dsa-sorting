#include "library.h"

// algorithms functions are defined here

// 1. selection sort
void selectionSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++){
        int min_index = i;
        for(int j = i + 1; j < n; j++)
            if(a[j] < a[min_index]) min_index = j;
        swap(a[i], a[min_index]);
    }
}
void selectionSort(int a[], int n, int& cnt) {
    cnt = 0;
    for(int i = 0; (++cnt and i < n - 1); i++){
            int min_index = i;
            for(int j = i + 1; (++cnt and j < n); j++)
                if(++cnt and a[j] < a[min_index]) min_index = j;
            swap(a[i], a[min_index]);
        }
}

// 2. insertion sort
void insertionSort1 (int a[], int n) {

}
void insertionSort2 (int a[], int n) {

}

// 3. bubble sort
void bubbleSort1 (int a[], int n) {

}
void bubbleSort2 (int a[], int n) {

}

// 4. shaker sort
void shakerSort1 (int a[], int n) {

}
void shakerSort2 (int a[], int n, int& cnt) {

}

// 5. shell sort
void shellSort1 (int a[], int n) {

}
void shellSort2 (int a[], int n) {

}

// 6. heap sort
void heapSort1 (int a[], int n) {

}
void heapSort2 (int a[], int n) {

}

// 7. merge sort
void mergeSort (int a[], int n) {

}
void mergeSort (int a[], int n, int& cnt) {

}

// 8. quick sort
void quickSort1 (int a[], int n) {

}
void quickSort2 (int a[], int n) {

}

// 9. counting sort
void countingSort1 (int a[], int n) {

}
void countingSort2 (int a[], int n) {

}

// 10. radix sort
void radixSort1 (int a[], int n) {

}
void radixSort2 (int a[], int n) {

}

// 11. flash sort
void flashSort1 (int a[], int n) {

}
void flashSort2 (int a[], int n) {

}
