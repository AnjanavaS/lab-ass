#include <stdio.h>

int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key)
            return 1;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}

int main() {
    int n, key;
    printf("Enter no.of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to be searched: ");
    scanf("%d", &key);

    
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

    if (binarySearch(a, n, key))
        printf("Element found");
    else
        printf("Element not found");

    return 0;
}