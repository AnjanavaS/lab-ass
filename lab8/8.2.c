#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* front = NULL;

struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue(int data, int priority) {
    struct Node* newNode = createNode(data, priority);
    
    if (front == NULL || priority < front->priority) {
        newNode->next = front;
        front = newNode;
        return;
    }
    
    struct Node* temp = front;
    while (temp->next != NULL && temp->next->priority <= priority) {
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    struct Node* temp = front;
    front = front->next;
    printf("Element %d with priority %d deleted\n", temp->data, temp->priority);
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Priority Queue:\n");
    printf("Priority Item\n");
    
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d        %d\n", temp->priority, temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, element, priority;
    
    while (1) {
        printf("Main Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(element, priority);
                break;
                
            case 2:
                dequeue();
                break;
                
            case 3:
                display();
                break;
                
            case 4:
                exit(0);
                
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}
