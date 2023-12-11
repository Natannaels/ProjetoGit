#include <stdio.h>

int isMatch(char *s, char *p) {
    if (*p == '\0') {
        return *s == '\0';
    }

    // Caso especial para '*'
    if (*(p + 1) == '*') {
        return (isMatch(s, p + 2) || (*s != '\0' && (*s == *p || *p == '.') && isMatch(s + 1, p)));
    }

    // Caso normal
    return (*s != '\0' && (*s == *p || *p == '.') && isMatch(s + 1, p + 1));
}

int main() {
    printf("%d\n", isMatch("aa", "a"));    
    printf("%d\n", isMatch("aa", "a*"));   
    printf("%d\n", isMatch("ab", ".*"));   

    return 0;
}
