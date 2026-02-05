//Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

#include <stdio.h>
int main() {
    int n, pos, i;
    int arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n", n);
    for (i = 0; i < n; i++)    {
        scanf("%d", &arr[i]);    }
    printf("Enter position to delete (1-based index): ");
    scanf("%d", &pos);
    if (pos < 1 || pos > n)
    {
        printf("Invalid position!\n");
        return 0;
    }
    for (i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("Array after deletion:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

/*Output
Enter number of elements: 5
Enter the elements:
2 3 5 6 8
Enter position to delete (1-based index): 3
Array after deletion:
2 3 6 8
*/