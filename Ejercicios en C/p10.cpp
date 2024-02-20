#include <stdio.h>

int mayor(int a, int b){
    int mayor;
    if(a > b){
        mayor = a;
    }else{
        mayor = b;
    }

    return mayor;
}

int main(){
    int num1, num2, num3, temp = 0;
    printf("Digite el primer numero: ");
    scanf("%d", &num1);
    printf("Digite el segundo numero: ");
    scanf("%d", &num2);
    printf("Digite el tercer numero: ");
    scanf("%d", &num3);
    
    temp = mayor(num1, num2);
    printf("El mayor de los 3 numeros es: %d", mayor(temp, num3));
    return 0;
}