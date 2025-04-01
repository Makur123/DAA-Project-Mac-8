#include <stdio.h>
#include <stdlib.h>

int comparisonCount = 0; // Global variable to count comparisons

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        comparisonCount++;
        if (arr[left] > arr[largest])
            largest = left;
    }
    
    if (right < n) {
        comparisonCount++;
        if (arr[right] > arr[largest])
            largest = right;
    }
    
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void insertHeap(int arr[], int *n, int value) {
    (*n)++;
    arr[*n - 1] = value;
    
    int i = *n - 1;
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        comparisonCount++;
        int temp = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void deleteHeap(int arr[], int *n) {
    if (*n <= 0) return;
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
}

void deleteNElements(int arr[], int *n, int N) {
    for (int i = 0; i < N && *n > 0; i++) {
        deleteHeap(arr, n);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100] = {50, 30, 40, 10, 5, 20, 35};
    int n = 7;
    
    printf("Original Heap: ");
    printArray(arr, n);
    
    int value = 60;
    insertHeap(arr, &n, value);
    
    printf("Heap after insertion: ");
    printArray(arr, n);
    
    int N = 3;
    deleteNElements(arr, &n, N);
    
    printf("Heap after deleting %d elements: ", N);
    printArray(arr, n);
    
    // Time complexity of heap insertion is O(log N)
    // Time complexity of heap deletion for N elements is O(N log N)
    printf("Time Complexity of deletion: O(N log N)\n");
    printf("Number of comparisons: %d\n", comparisonCount);
    
    return 0;
}
