#include <stdio.h>

int n, adj[10][10], visited[10];

void DFS(int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;
    for(i = 0; i < n; i++) {
        if(adj[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

int main() {
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter start vertex: ");
    scanf("%d", &start);

    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("Depth First Search: ");
    DFS(start);
    return 0;
}