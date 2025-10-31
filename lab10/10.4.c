#include <stdio.h>

int main() {
    int n;
    printf("Enter number of vertex: ");
    scanf("%d", &n);

    int adj[n][n];
    char ch;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                printf("Vertices %d & %d are Adjacent ? (Y/N): ", i + 1, j + 1);
                scanf(" %c", &ch);
                if (ch == 'Y' || ch == 'y')
                    adj[i][j] = 1;
            }
        }
    }

    int in_degree[n], out_degree[n], total_degree[n];

    for (int i = 0; i < n; i++) {
        in_degree[i] = 0;
        out_degree[i] = 0;
        total_degree[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1)
                out_degree[i]++;
            if (adj[j][i] == 1)
                in_degree[i]++;
        }
        total_degree[i] = in_degree[i] + out_degree[i];
    }

    printf("\nVertex\tIn_Degree\tOut_Degree\tTotal_Degree\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, in_degree[i], out_degree[i], total_degree[i]);

    return 0;
}