//Implement linear search to find key k in an array. Count and display the number of comparisons performed.

#include <stdio.h>
int main() {
    int n, k, i;
    int arr[100];
    int comparisons = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)    {
        scanf("%d", &arr[i]);    }
    printf("Enter key to search: ");
    scanf("%d", &k);
    for (i = 0; i < n; i++)
    {
        comparisons++;
        if (arr[i] == k)
        {
            printf("Found at index %d\n", i + 1);
            break;
        }
    }
    if (i == n)
    {
        printf("Key not found\n");
    }
    printf("Comparisons: %d\n", comparisons);
    return 0;
}

/*Output
Enter number of elements: 5
Enter the elements:
10 20 30 40  50
Enter key to search: 30
Found at index 3
Comparisons: 3
*/