#include <stdio.h>

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pivot = a[low];
        int i = low + 1;
        int j = high;
        int temp;
        while (1) {
            while (i <= high && a[i] <= pivot)
                i++;
            while (a[j] > pivot)
                j--;
            if (i > j)
                break;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        temp = a[low];
        a[low] = a[j];
        a[j] = temp;

        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
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

    quickSort(a, 0, n - 1);

    printf("Ascending order: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}