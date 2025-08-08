#include<stdio.h>

#define MAX 100

void countNonZeroElements(int matrix[][MAX], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    printf("Number of nonzero elements: %d\n", count);
}

void displayUpperTriangular(int matrix[][MAX], int n) {
    printf("Upper triangular matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i) {
                printf("0 ");
            } else {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void displayAboveBelowDiagonal(int matrix[][MAX], int n) {
    printf("Elements just above the main diagonal:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", matrix[i][i + 1]);
    }
    printf("\n");

    printf("Elements just below the main diagonal:\n");
    for (int i = 1; i < n; i++) {
        printf("%d ", matrix[i][i - 1]);
    }
    printf("\n");
}

int main() {
    int matrix[MAX][MAX];
    int n, choice;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Matrix size exceeds limit.\n");
        return 0;
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    while (1) {
        printf("\nMENU:\n");
        printf("1. Find the number of nonzero elements\n");
        printf("2. Display upper triangular matrix\n");
        printf("3. Display elements just above and below the main diagonal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                countNonZeroElements(matrix, n);
                break;
            case 2:
                displayUpperTriangular(matrix, n);
                break;
            case 3:
                displayAboveBelowDiagonal(matrix, n);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
