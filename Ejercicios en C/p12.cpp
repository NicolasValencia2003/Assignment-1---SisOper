#include <stdio.h>
const int CAP = 100;

void Decimal_Octal(int numero_decimal) {
    int numero_octal[CAP], i = 0, j;

    while (numero_decimal != 0) {
        numero_octal[i++] = numero_decimal % 8;
        numero_decimal /= 8;
    }

    printf("en octal es: ");
    for (j = i - 1; j >= 0; j--) {
        printf("%d", numero_octal[j]);
    }
}

void Decimal_Hexadecimal(int numero_decimal) {
    char hex[CAP];
    int i = 0, j;

    while (numero_decimal != 0) {
        int temp = 0;
        temp = numero_decimal % 16;
        if (temp < 10) {
            hex[i] = temp + 48;
            i++;
        } else {
            hex[i] = temp + 55;
            i++;
        }
        numero_decimal /= 16;
    }

    printf("en hexadecimal es: ");
    for (j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}

int main() {
    int opcion;
    do {
        printf("\nDeseas ver los numeros del 1-10 en:\n");
        printf("1. Octal\n");
        printf("2. Decimal\n");
        printf("3. Hexadecimal\n");
        printf("4. Salir\n");
        
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                for (int i = 1; i <= 10; i++) {
                    printf("El numero: %d ", i);
                    Decimal_Octal(i);
                    printf("\n");
                }
                break;
            case 2:
                for (int i = 1; i <= 10; i++) {
                    printf("El numero: %d en decimal es %d\n", i, i);
                }
                break;
            case 3:
                for (int i = 1; i <= 10; i++) {
                    printf("El numero: %d ", i);
                    Decimal_Hexadecimal(i);
                    printf("\n");
                }
                break;
            case 4:
                break;
            default:
                printf("\nOpcion invalida.\n");
                break;
        }
    } while(opcion != 4);
    
    return 0;
}