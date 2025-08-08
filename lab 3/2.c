#include <stdio.h>

int main() {
    int sparse1[100][3],sparse2[100][3];
    int i, j;
    int n1, n2;

    printf("Enter first sparse matrix in 3-tuple format\n");
    scanf("%d %d %d", &sparse1[0][0], &sparse1[0][1], &sparse1[0][2]);
    n1 = sparse1[0][2];     
    for(i = 1; i <= n1; i++) {  
        scanf("%d %d %d", &sparse1[i][0], &sparse1[i][1], &sparse1[i][2]);
    }

    printf("Enter second sparse matrix in 3-tuple format\n");
    scanf("%d %d %d", &sparse2[0][0], &sparse2[0][1], &sparse2[0][2]);
    n2 = sparse2[0][2];     
    for(i = 1; i <= n2; i++) {  
        scanf("%d %d %d", &sparse2[i][0], &sparse2[i][1], &sparse2[i][2]);
    }
    int result[100][3];
    if(sparse1[0][0] != sparse2[0][0] || sparse1[0][1] != sparse2[0][1]) {
        printf("Matrices cannot be added\n");
        return 0;
    }
    else {
        result[0][0] = sparse1[0][0];
        result[0][1] = sparse1[0][1];
        result[0][2] = 0;
        int k = 1;
        for(i = 1; i <= n1; i++) {
            int found = 0;  
            for(j = 1; j <= n2; j++) {
                if(sparse1[i][0] == sparse2[j][0] && sparse1[i][1] == sparse2[j][1]) {
                    result[k][0] = sparse1[i][0];
                    result[k][1] = sparse1[i][1];
                    result[k][2] = sparse1[i][2] + sparse2[j][2];
                    k++;
                    found = 1;
                    break;
                }
            }
            if(!found) {
                result[k][0] = sparse1[i][0];
                result[k][1] = sparse1[i][1];
                result[k][2] = sparse1[i][2];
                k++;
            }
        }
        for(i = 1; i <= n2; i++) {
            int found = 0;
            for(j = 1; j <= n1; j++) {
                if(sparse2[i][0] == sparse1[j][0] && sparse2[i][1] == sparse1[j][1]) {
                    found = 1;
                    break;
                }
            }
            if(!found) {
                result[k][0] = sparse2[i][0];
                result[k][1] = sparse2[i][1];
                result[k][2] = sparse2[i][2];
                k++;        
            }
        }
        printf("Resultant sparse matrix in 3-tuple format:\n");
        result[0][2] = k - 1;  
        for(i=0; i < k; i++) {
            printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
        }        
    } 
    return 0;

            }