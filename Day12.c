//Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

#include <stdio.h>
int main() {
    int n, i, j;
    int matrix[10][10];
    int isSymmetric = 1;
    printf("Enter the order of square matrix: ");
    scanf("%d", &n);
    printf("Enter elements of the matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if(isSymmetric == 0)
            break;
    }
    if(isSymmetric == 1)
        printf("The matrix is Symmetric.\n");
    else
        printf("The matrix is NOT Symmetric.\n");
    return 0;
}

/*Output
Enter the order of square matrix: 3 3
Enter elements of the matrix:
1 2 3
4 5 6
7 8 9
The matrix is NOT Symmetric.
*/
