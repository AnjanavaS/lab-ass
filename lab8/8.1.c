#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Deque {
    int arr[MAX];
    int front;
    int rear;
    int size;
};

void initDeque(struct Deque* dq, int sz) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = sz;
}

int isEmpty(struct Deque* dq) {
    return dq->front == -1;
}

int isFull(struct Deque* dq) {
    return ((dq->rear + 1) % dq->size) == dq->front;
}

void insertRight(struct Deque* dq, int element) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % dq->size;
    }
    dq->arr[dq->rear] = element;
    printf("Element inserted\n");
}

void insertLeft(struct Deque* dq, int element) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + dq->size) % dq->size;
    }
    dq->arr[dq->front] = element;
    printf("Element inserted\n");
}

void deleteLeft(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("%d deleted\n", dq->arr[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % dq->size;
    }
}

void deleteRight(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("%d deleted\n", dq->arr[dq->rear]);
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + dq->size) % dq->size;
    }
}

void display(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear) break;
        i = (i + 1) % dq->size;
    }
    printf("\n");
}

void inputRestrictedDeque() {
    struct Deque dq;
    int size, choice, element;

    printf("Enter the size of Deque: ");
    scanf("%d", &size);
    initDeque(&dq, size);

    while (1) {
        printf("\nInput restricted Dequeue Menu\n");
        printf("1. Insert at right\n");
        printf("2. Delete from left\n");
        printf("3. Delete from right\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                insertRight(&dq, element);
                break;
            case 2:
                deleteLeft(&dq);
                break;
            case 3:
                deleteRight(&dq);
                break;
            case 4:
                display(&dq);
                break;
            case 5:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}

void outputRestrictedDeque() {
    struct Deque dq;
    int size, choice, element;

    printf("Enter the size of Deque: ");
    scanf("%d", &size);
    initDeque(&dq, size);

    while (1) {
        printf("\nOutput restricted Dequeue Menu\n");
        printf("1. Insert at left\n");
        printf("2. Insert at right\n");
        printf("3. Delete from right\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                insertLeft(&dq, element);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &element);
                insertRight(&dq, element);
                break;
            case 3:
                deleteRight(&dq);
                break;
            case 4:
                display(&dq);
                break;
            case 5:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Input restricted Deque\n");
        printf("2. Output restricted Deque\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputRestrictedDeque();
                break;
            case 2:
                outputRestrictedDeque();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
