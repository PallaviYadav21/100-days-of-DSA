//Given an array of integers, count the number of subarrays whose sum is equal to zero.

#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == 0) {
                count++;
            }
        }
    }
    printf("Number of subarrays with sum zero: %d\n", count);
    return 0;
}

/*Output
Enter the number of elements: 6
Enter 6 integers:
1 -1 2 -2 3 -3
Number of subarrays with sum zero: 6
*/