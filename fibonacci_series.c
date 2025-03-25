#include <stdio.h>

static int operations = 0;

void printFib(int n) {
    if (n < 1) {  
        printf("Invalid Number of terms\n");
        operations++; 
        return;
    }

    int prev1 = 1;
    int prev2 = 0;
    operations += 2; 

    printf("%d ", prev2);
    operations++; 

    if (n == 1) {
        operations++;
        return;
    }

    printf("%d ", prev1);
    for (int i = 3; i <= n; i++) {
        
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;

        printf("%d ", curr);
        operations++; 
    }
}

int main() {
    int n = 9;
    operations++; 

    printFib(n);

    printf("\nTotal operations performed: %d\n", operations);
    operations++; 

    return 0;
}
