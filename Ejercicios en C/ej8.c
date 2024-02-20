#include <stdio.h>

int isUpperCase(char c) {
    // ASCII values of uppercase letters range from 65 to 90
    if (c >= 'A' && c <= 'Z') {
        return 1; // True, character is uppercase
    } else {
        return 0; // False, character is not uppercase
    }
}

int main() {
    char character;
    
    printf("Enter a character: ");
    scanf("%c", &character);
    
    if (isUpperCase(character)) {
        printf("%c is an uppercase letter.\n", character);
    } else {
        printf("%c is not an uppercase letter.\n", character);
    }
    
    return 0;
}
