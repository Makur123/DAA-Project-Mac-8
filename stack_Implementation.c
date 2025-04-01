#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
        printf("Pushed %d onto the stack\n", value);
    } else {
        printf("Stack Overflow!\n");
    }
}

int pop() {
    if (top >= 0) {
        printf("Popped %d from the stack\n", stack[top]);
        return stack[top--];
    } else {
        printf("Stack Underflow!\n");
        return -1;
    }
}

void multiPop(int k) {
    for (int i = 0; i < k; i++) {
        pop();
    }
}

void printStack() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Current stack: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int k;
    int value;
    printf("Enter number of elements to push onto the stack: ");
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value to push: ");
        scanf("%d", &value);
        push(value);
    }

    printf("Enter the number of elements to pop: ");
    scanf("%d", &k);
    multiPop(k);
    
    printStack();

    // Amortized time complexity for push and pop: O(1) for each operation
    printf("Amortized Time Complexity: O(1) per operation for push and pop\n");

    return 0;
}
