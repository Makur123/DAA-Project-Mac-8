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

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100] = {10, 20, 30, 25, 5, 40, 35};
    int n = 7;
    
    printf("Original Heap: ");
    printArray(arr, n);
    
    int value = 50;
    insertHeap(arr, &n, value);
    
    printf("Heap after insertion: ");
    printArray(arr, n);
    
    // Time complexity of heap insertion is O(log N)
    printf("Time Complexity: O(log N)\n");
    printf("Number of comparisons: %d\n", comparisonCount);
    
    return 0;
}
