#include <stdio.h>

int esMinuscula(char l) {
    return (l >= 'a' && l <= 'z');
}

int main() {
    char l;
    printf("Ingresa una letra: ");
    scanf("%c", &l);

    if (esMinuscula(l)) {
        printf("La letra es una minuscula.\n");
    } else {
        printf("La letra no es minuscula.\n");
    }

    return 0;
}