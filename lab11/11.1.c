#include <stdio.h>

void insertionSortAsc(int a[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void insertionSortDesc(int a[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    int n;
    printf("Enter no.of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    insertionSortAsc(a, n);
    printf("Ascending order: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    insertionSortDesc(a, n);
    printf("\nDescending order: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}