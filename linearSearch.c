#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int key = 10;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int)*n);
    printf("Enter the elements of the array:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if(arr[i] == key){
            printf("Element %d found at index %d\n", key, i);
            break;
        }else if(i == n-1){
            printf("Element %d not found in the array\n", key);
        }
}}