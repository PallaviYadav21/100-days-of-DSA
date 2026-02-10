//Read a string and check if it is a palindrome using two-pointer comparison.

#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int left, right, flag = 1;
    printf("Enter a String: ");
    scanf("%s", str);
    left = 0;
    right = strlen(str) - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            flag = 0;
            break;
        }
        left++;
        right--;
    }
    if (flag)
        printf("The String is a palindrome.");
    else
        printf("The String is not a palindrome.");
    return 0;
}

/*Output
Enter a String: madam
The String is a palindrome.
*/