//Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

#include <stdio.h>
int main() {
    int n;
    printf("Enter order of square matrix: ");
    scanf("%d", &n);
    int matrix[n][n];
    int isIdentity = 1;
    printf("Enter matrix elements:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {           
            if(i == j && matrix[i][j] != 1) {
                isIdentity = 0;
                break;
            }  
            if(i != j && matrix[i][j] != 0) {
                isIdentity = 0;
                break;
            }
        }
    }
    if(isIdentity == 1)
        printf("The matrix is an Identity Matrix.");
    else
        printf("The matrix is NOT an Identity Matrix.");
    return 0;
}

/*Output
Enter order of square matrix: 3
Enter matrix elements:
1 0 0
0 1 0
0 0 1
The matrix is an Identity Matrix.

Enter order of square matrix: 3
Enter matrix elements:
0 1 0
1 0 0
0 0 1
The matrix is NOT an Identity Matrix.
*/