//Given an array of integers, rotate the array to the right by k positions.

#include <stdio.h>
int main() {
    int n, k;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n], temp[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter number of rotations (k): ");
    scanf("%d", &k);
    k = k % n;
    for(int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }
    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    printf("Array after rotation:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

/*Output
Enter size of array: 5
Enter 5 elements:
1 2 3 4 5 
Enter number of rotations (k): 2
Array after rotation:
4 5 1 2 3 
*/