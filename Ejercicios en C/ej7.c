#include <stdio.h>

void fibonacci(int n) {
    int a = 0, b = 1, c, i;
    
    printf("Fibonacci Series up to %d terms:\n", n);
    
    if (n >= 1)
        printf("%d ", a);
    if (n >= 2)
        printf("%d ", b);
    
    for (i = 3; i <= n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
}

int main() {
    int n;
    
    printf("Enter the number of terms for Fibonacci Series: ");
    scanf("%d", &n);
    
    fibonacci(n);
    
    return 0;
}
