#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int count = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int) * n);
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        count++;
    }
    for (int i = 0; i < n; i++){
        int min_idx = i;

        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[min_idx])
                min_idx = j;
                count++;
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
        count++;
    }
    printf("Sorted array in ascending order:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
        count++;
    }
    printf("\nTotal number of comparisons: %d\n", count); 
}