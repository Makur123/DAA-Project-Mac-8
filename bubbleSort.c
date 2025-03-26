#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int count = 0;
    printf("Enter the size of the array: \n");
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int) * n);
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        count ++;
    }
    for(int i = 0; i < n-1; i++){
        count++;
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
            }
        }
    }
    printf("Sorted array in ascending order:\n ");
    for(int i = 0; i < n; i++){
        printf("%d \t ", arr[i]);
        count++;
    }
    printf("\nTotal number of comparisons: %d\n", count);
    free(arr);
}