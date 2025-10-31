#include <stdio.h>

void selectionSortAsc(int a[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void selectionSortDesc(int a[], int n) {
    int i, j, max, temp;
    for (i = 0; i < n - 1; i++) {
        max = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] > a[max])
                max = j;
        }
        temp = a[i];
        a[i] = a[max];
        a[max] = temp;
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

    selectionSortAsc(a, n);
    printf("Ascending order: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    selectionSortDesc(a, n);
    printf("\nDescending order: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}