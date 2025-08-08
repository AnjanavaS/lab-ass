#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtPosition(struct Node **head, int data, int position) {
    struct Node *newNode = createNode(data);

    if (position == 1) { 
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPosition(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = *head;

    if (position == 1) { 
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node *prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int countNodes(struct Node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void traverseList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf("-> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int n, data, choice, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtPosition(&head, data, i + 1); 
    }
   
    do {
        printf("\nMENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Count\n");
        printf("4. Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPosition(&head, data, position);
            printf("Node inserted\n");
            break;

        case 2:
            printf("Enter position: ");
            scanf("%d", &position);
            deleteAtPosition(&head, position);
            printf("Node deleted\n");
            break;

        case 3:
            printf("The total number of nodes: %d\n", countNodes(head));
            break;

        case 4:
            printf("The list is: ");
            traverseList(head);
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
