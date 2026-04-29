//Problem: Implement Binary Search Iterative - Implement the algorithm.

#include <stdio.h>
void sort(int arr[], int n) {
    int i, j, min_idx, temp;
    for(i = 0; i < n-1; i++) {
        min_idx = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main() {
    int n, i, key, result;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nEnter element to search: ");
    scanf("%d", &key);
    result = binarySearch(arr, n, key);
    if(result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
    return 0;
}

/*Output
Enter number of elements: 5
Enter elements: 64 67 35 87 13
Sorted array:
13 35 64 67 87 
Enter element to search: 67
Element found at index 3
*/