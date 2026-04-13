//Problem Statement Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

#include <stdio.h>
#include <string.h>
int main() {
    char s[1000];
    printf("Enter the string: ");
    fgets(s, sizeof(s), stdin);
    int visited[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '\n') continue;
        int index = s[i] - 'a';
        if (visited[index] == 1) {
            printf("First repeated character: %c", s[i]);
            return 0;
        }
        visited[index] = 1;
    }
    printf("-1");
    return 0;
}

/*Output
Enter the string: helloworld
First repeated character: l
*/