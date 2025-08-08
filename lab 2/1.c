#include<stdio.h>

#define MAX 100

void insertElement(int arr[], int *n, int element, int position) {
    if (position < 0 || position > *n || *n >= MAX) {
        printf("Invalid position or array full!\n");
        return;
    }

    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    (*n)++;
    printf("Inserted %d at position %d.\n", element, position);
}

void deleteElement(int arr[], int *n, int position) {
    if (position < 0 || position >= *n) {
        printf("Invalid position!\n");
        return;
    }

    int deleted = arr[position];
    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;
    printf("Deleted element %d from position %d.\n", deleted, position);
}

void linearSearch(int arr[], int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            printf("Element %d found at position %d.\n", element, i);
            return;
        }
    }
    printf("Element %d not found in the array.\n", element);
}

void traverseArray(int arr[], int n) {
    printf("Array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Index %d: %d\n", i, arr[i]);
    }
}

int main() {
    int arr[MAX];
    int n, choice, element, position;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Array size exceeds limit.\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nMENU:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Linear search\n");
        printf("4. Traverse array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert at (0-based index): ");
                scanf("%d", &position);
                insertElement(arr, &n, element, position);
                break;

            case 2:
                printf("Enter position to delete from (0-based index): ");
                scanf("%d", &position);
                deleteElement(arr, &n, position);
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &element);
                linearSearch(arr, n, element);
                break;

            case 4:
                traverseArray(arr, n);
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
