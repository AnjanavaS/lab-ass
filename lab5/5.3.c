#include <stdio.h>
#include <stdlib.h>

struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
};

struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int row, int col, int value) {
    struct Node* newNode = createNode(row, col, value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displaySparseMatrix(struct Node* head, int rows, int cols, int count) {
    printf("sparse matrix in 3-tuple format\n");
    printf("%d %d %d\n", rows, cols, count);
    
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d %d %d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

int main() {
    int rows, cols;
    struct Node* head = NULL;
    int count = 0;
    
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);
    
    printf("Enter elements of sparse matrix: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int element;
            scanf("%d", &element);
            if (element != 0) {
                insertNode(&head, i, j, element);
                count++;
            }
        }
    }
    
    displaySparseMatrix(head, rows, cols, count);
    
    return 0;
}
