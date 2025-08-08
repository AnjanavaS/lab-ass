#include<stdio.h>

#define MAX 100

void displaySparseMatrix(int matrix[][MAX], int rows, int cols) {
    int count = 0;
    printf("3-tuple representation (row, column, value):\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                printf("%d\t%d\t%d\n", i, j, matrix[i][j]);
                count++;
            }
        }
    }
    if (count == 0) {
        printf("Matrix has no nonzero elements.\n");
    }
}

int main() {
    int matrix[MAX][MAX];
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    if (rows > MAX || cols > MAX) {
        printf("Matrix size exceeds limit.\n");
        return 0;
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    displaySparseMatrix(matrix, rows, cols);

    return 0;
}
