#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;  
    struct Node* next;  
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end (for initial list creation)
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert node at specific position
void insertAtPosition(int data, int position) {
    if (position < 1) {
        printf("Position should be >= 1\n");
        return;
    }
    
    struct Node* newNode = createNode(data);
    
    // Insert at beginning
    if (position == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        printf("Node inserted\n");
        return;
    }
    
    struct Node* temp = head;
    int count = 1;
    
    // Traverse to the position
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
    
    if (count == position) {
        // Insert at the found position
        newNode->next = temp;
        newNode->prev = temp->prev;
        
        if (temp->prev != NULL) {
            temp->prev->next = newNode;
        }
        temp->prev = newNode;
    } else {
        // Insert at end if position is beyond list length
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    
    printf("Node inserted\n");
}

// Function to delete node from specific position
void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    if (position < 1) {
        printf("Position should be >= 1\n");
        return;
    }
    
    struct Node* temp = head;
    int count = 1;
    
    // Find the node to delete
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
    
    if (temp == NULL) {
        printf("Position not found\n");
        return;
    }
    
    // If it's the first node
    if (temp->prev == NULL) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else {
        temp->prev->next = temp->next;
    }
    
    // If it's not the last node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    printf("Node deleted from position %d\n", position);
    free(temp);
}

// Function to traverse and display the list
void traverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head;
    printf("The list is: ");
    
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf("-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to display menu
void displayMenu() {
    printf("\nMENU:\n");
    printf("1. Insert the node at a position\n");
    printf("2. Delete a node from specific position\n");
    printf("3. Traversal\n");
    printf("4. Exit\n");
}

int main() {
    int n, element, choice, position;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        insertAtEnd(element);
    }
    
    while (1) {
        displayMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(element, position);
                break;
                
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
                
            case 3:
                traverse();
                break;
                
            case 4:
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
