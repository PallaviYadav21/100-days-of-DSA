//Given an array of n integers, reverse the array in-place using two-pointer approach.

#include <stdio.h>
int main()  {
    int n, i;
    int arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)  {
        scanf("%d", &arr[i]);   }
    int left = 0;
    int right = n - 1;
    int temp;
    while (left < right)  {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
    printf("Reversed array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

/*Output
Enter number of elements: 5
Enter 5 elements:
1 2 3 4 5
Reversed array:
5 4 3 2 1
*/