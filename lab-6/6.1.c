#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int item) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

void traverse() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;
    while (1) {
        printf("Main Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to be pushed into the stack: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != -1) {
                    printf("%d deleted from Stack\n", item);
                }
                break;
            case 3:
                if (isEmpty()) {
                    printf("Stack empty: True\n");
                } else {
                    printf("Stack empty: False\n");
                }
                break;
            case 4:
                if (isFull()) {
                    printf("Stack full: True\n");
                } else {
                    printf("Stack full: False\n");
                }
                break;
            case 5:
                printf("Stack: ");
                traverse();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}
