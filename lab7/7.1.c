#include <stdio.h>
#include <stdlib.h>

int queue[100];
int front = -1;
int rear = -1;
int maxSize;

void enqueue(int element) {
    if (rear == maxSize - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = element;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Element deleted\n");
    front++;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

int isEmpty() {
    return (front == -1 || front > rear);
}

int isFull() {
    return (rear == maxSize - 1);
}

void traverse() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, element;
    
    printf("Enter the size of Queue: ");
    scanf("%d", &maxSize);
    
    while (1) {
        printf("Main Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                if (isEmpty()) {
                    printf("Queue is empty: True\n");
                } else {
                    printf("Queue is empty: False\n");
                }
                break;
            case 4:
                if (isFull()) {
                    printf("Queue is full: True\n");
                } else {
                    printf("Queue is full: False\n");
                }
                break;
            case 5:
                traverse();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option!\n");
        }
    }
    
    return 0;
}
