//Given an array of integers, count the frequency of each distinct element and print the result.

#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    int visited[n];
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        if(visited[i] == 1)
            continue;
        int count = 1;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }
        printf("%d occurs %d times\n", arr[i], count);
    }
    return 0;
}

/*Output
Enter number of elements: 8
Enter elements:
1 2 2 1 1 3 3 5    
1 occurs 3 times
2 occurs 2 times
3 occurs 2 times
5 occurs 1 times
*/