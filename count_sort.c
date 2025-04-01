#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparisonCount = 0; // Global variable to count comparisons

void countSort(int arr[], int n) {
    int max = arr[0], min = arr[0];
    
    // Find the range of the array
    for (int i = 1; i < n; i++) {
        comparisonCount++; // Increment comparison count
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    
    int range = max - min + 1;
    int* count = (int*)calloc(range, sizeof(int)); // Initialize count array
    int* output = (int*)malloc(n * sizeof(int));   // Output array
    
    // Store count of occurrences
    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }
    
    // Change count[i] to store the position of this element in output array
    for (int i = 1; i < range; i++) {
        comparisonCount++; // Increment comparison count
        count[i] += count[i - 1];
    }
    
    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    
    // Copy the sorted elements back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    
    // Free allocated memory
    free(count);
    free(output);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    countSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    // Time complexity of Count Sort is O(N + K), where K is the range of numbers.
    printf("Time Complexity: O(N + K)\n");
    printf("Number of comparisons: %d\n", comparisonCount);
    
    return 0;
}
