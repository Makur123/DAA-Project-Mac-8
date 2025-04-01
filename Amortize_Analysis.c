#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int maxSize;
    printf("Enter the maximum length of the array: ");
    scanf("%d", &maxSize);

    int currentSize = 0;
    int capacity = 1;
    int* arr = (int*)malloc(capacity * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Start entering numbers (up to %d):\n", maxSize);
    for (int i = 0; i < maxSize; i++) {
        int value;
        scanf("%d", &value);
        
        if (currentSize == capacity) {
            capacity *= 2;
            arr = (int*)realloc(arr, capacity * sizeof(int));
            if (arr == NULL) {
                printf("Memory reallocation failed!\n");
                return 1;
            }
        }
        
        arr[currentSize++] = value;
    }

    printf("Final Dynamic Array: ");
    printArray(arr, currentSize);
    
    // Amortized time complexity: O(1) for insertions, O(N) for total insertions due to doubling
    printf("Amortized Time Complexity: O(1) per insertion, O(N) total\n");
    
    free(arr);
    return 0;
}
