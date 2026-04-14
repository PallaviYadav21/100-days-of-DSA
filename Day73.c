//Problem Statement: Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

#include <stdio.h>
#include <string.h>
int main() {
    char s[1000];
    int freq[26] = {0};
    printf("Enter a string: ");
    scanf("%s", s);
    for(int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }
    for(int i = 0; s[i] != '\0'; i++) {
        if(freq[s[i] - 'a'] == 1) {
            printf("First non-repeating character: %c", s[i]);
            return 0;
        }
    }
    printf("No non-repeating character: $");
    return 0;
}

/*Output
Enter a string: greeksforgreeks
First non-repeating character: f
*/