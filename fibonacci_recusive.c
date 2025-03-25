#include <stdio.h>
static int count = 0;
int fibbonacci(int n) {
    if(n == 0){
       return 0;
       count++;
    } else if(n == 1) {
       return 1;
       count++;
    } else {
       return (fibbonacci(n-1) + fibbonacci(n-2));
       count++;
    }
 }
 
 int main() {
    int n = 5;
    int i;
    printf("Fibbonacci of %d: " , n);
     
    for(i = 0;i<n;i++) {
       printf("%d ",fibbonacci(i)); 
       count++;           
    }
    printf("\nTime complexity : %d\n", count);
 }