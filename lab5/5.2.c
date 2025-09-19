#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }
    
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->next = *head;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Clinkedlist: ");
    struct Node* temp = head;
    
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);  
    
    printf("\n");
}

void freeList(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    
    struct Node* current = *head;
    struct Node* nextNode;
    
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = NULL;
    
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    int n, data;
        printf("Enter no.of nodes: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        printf("Enter info of node%d: ", i);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }
    
    displayList(head);

    freeList(&head);

    return 0;
}
