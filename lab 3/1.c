#include<stdio.h>
#include<stdio.h>

int main() {
    int sparse[100][3], transpose[100][3];
    int i, j, n;

    printf("Enter sparse matrix in 3-tuple format\n");
  
    scanf("%d %d %d", &sparse[0][0], &sparse[0][1], &sparse[0][2]);
    n = sparse[0][2];

   
    for(i = 1; i <= n; i++) {
        scanf("%d %d %d", &sparse[i][0], &sparse[i][1], &sparse[i][2]);
    }

  
    transpose[0][0] = sparse[0][1];
    transpose[0][1] = sparse[0][0];
    transpose[0][2] = sparse[0][2];

    int k = 1;
    for(i = 0; i < sparse[0][1]; i++) { 
        for(j = 1; j <= n; j++) {
            if(sparse[j][1] == i) {
                transpose[k][0] = sparse[j][1];
                transpose[k][1] = sparse[j][0];
                transpose[k][2] = sparse[j][2];
                k++;
            }
        }
    }

    printf("Transpose in 3-tuple format:\n");
    for(i = 0; i <= n; i++) {
        printf("%d %d %d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    }

    return 0;
}