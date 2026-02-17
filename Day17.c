//Write a program to find the maximum and minimum values present in a given array of integers.

#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    int min = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];

        if(arr[i] < min)
            min = arr[i];
    }
    printf("Maximum value = %d\n", max);
    printf("Minimum value = %d\n", min);
    return 0;
}

/*Output
Enter number of elements: 6
Enter elements:
2 3 1 6 9 7
Maximum value = 9
Minimum value = 1
*/