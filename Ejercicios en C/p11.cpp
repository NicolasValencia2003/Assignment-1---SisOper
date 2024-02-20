#include <stdio.h>

int explicitTypecasting(float a){
    int temp = (int)a;
    return temp;
}

float implicitTypecasting(int b){
    float temp2 = b;
    return b;
}

int main(){
   int opcion, num1;
   float num2;
    do {
        printf("\nQue Typecasting desea hacer?\n");
        printf("1. Implicit\n");
        printf("2. Explicit\n");
        printf("3. Salir\n");
        
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                printf("Digite un numero entero(Int): ");
                scanf("%d", &num1);
                printf("Su numero en flotante es: %.2f\n", implicitTypecasting(num1));
                break;
            case 2:
                printf("Digite un numero flotante(Float): ");
                scanf("%f", &num2);
                printf("Su numero en entero es: %d\n", explicitTypecasting(num2));
                break;
            case 3:
                break;
            default:
                printf("\nOpcion invalida.\n");
                break;
        }
    } while(opcion != 3);
    
    return 0;
}