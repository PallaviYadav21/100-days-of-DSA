// Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (n == 0) {
        return 0;
    }
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    printf("Array after removing duplicates:\n");
    for (int i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

/*Output
Enter number of elements: 6
Enter sorted array elements:
1 1 2 2 3 3
Array after removing duplicates:
1 2 3
*/