//Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

#include <stdio.h>
int main() {
    int n;
    int sum = 0;
    printf("Enter order of square matrix: ");
    scanf("%d", &n);
    int matrix[n][n];
    printf("Enter matrix elements:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        sum = sum + matrix[i][i];
    }
    printf("Sum of primary diagonal elements = %d", sum);
    return 0;
}

/*Output
1 3 5                                   
2 4 6
7 8 9
Sum of primary diagonal elements = 14
*/