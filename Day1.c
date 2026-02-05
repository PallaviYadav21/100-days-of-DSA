//Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

#include <stdio.h>
int main() {
    int n, pos, x, i;
    int arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n", n);
    for (i = 0; i < n; i++)  {
        scanf("%d", &arr[i]);  }
    printf("Enter element to insert: ");
    scanf("%d", &x);
    printf("Enter position (1-based index): ");
    scanf("%d", &pos);
    if (pos < 1 || pos > n + 1)  {
        printf("Invalid position!\n");
        return 0;
    }
    for (i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = x;
    n++;
    printf("Array after insertion:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

/*Output
Enter number of elements: 5
Enter the elements:
1 2 4 5 6
Enter element to insert: 3
Enter position (1-based index): 3
Array after insertion:
1 2 3 4 5 6
*/
