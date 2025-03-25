#include <stdio.h>

static int operations = 0;

int binary_search(int arr[], int low, int high, int x) {
    operations++; // Counting function call

    if (high >= low) {
        int mid = (high + low) / 2;
        operations++; // Counting mid calculation
        
        if (arr[mid] == x) {
            operations++;
            return mid;
        }
        if (arr[mid] > x) {
            operations++;
            return binary_search(arr, low, mid - 1, x);
        }
        operations++;
        return binary_search(arr, mid + 1, high, x);
    }
    return -1; // Return -1 if element is not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    
    operations++;
    int result = binary_search(arr, 0, n - 1, x);
    operations++;

    if (result == -1) {
        printf("Element is not present in array\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    printf("Number of operations performed: %d\n", operations);
    return 0;
}
