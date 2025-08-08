#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;   
    int power;   
    struct Node *next;
};


struct Node* createNode(int coeff, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}


void insertEnd(struct Node** head, int coeff, int power) {
    struct Node* newNode = createNode(coeff, power);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayPoly(struct Node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->power);
        if (head->next != NULL)
            printf("+");
        head = head->next;
    }
    printf("\n");
}

void createPolynomial(struct Node** head) {
    int maxPower, coeff;
    printf("Enter the Maximum power of x: ");
    scanf("%d", &maxPower);
    for (int i = maxPower; i >= 0; i--) {
        printf("Enter the coefficient of degree %d: ", i);
        scanf("%d", &coeff);
        insertEnd(head, coeff, i);
    }
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->power > poly2->power) {
            insertEnd(&result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        }
        else if (poly1->power < poly2->power) {
            insertEnd(&result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        }
        else {
            insertEnd(&result, poly1->coeff + poly2->coeff, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
 
    while (poly1 != NULL) {
        insertEnd(&result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }
   
    while (poly2 != NULL) {
        insertEnd(&result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }
    return result;
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;

    printf("Polynomial-1:\n");
    createPolynomial(&poly1);

    printf("Polynomial-2:\n");
    createPolynomial(&poly2);

    sum = addPolynomials(poly1, poly2);

    printf("Sum: ");
    displayPoly(sum);

    return 0;
}
