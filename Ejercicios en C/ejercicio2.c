#include <stdio.h>

int main() {
    int number, i, isPrime = 1;

    // Ask the user to enter a number
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    // Check if the number is less than 2
    if (number < 2) {
        printf("Prime numbers start from 2. Please enter a number greater than or equal to 2.\n");
        return 0;
    }

    // Check for prime
    for (i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
            isPrime = 0;
            break;
        }
    }

    // Print the result
    if (isPrime)
        printf("%d is a prime number.\n", number);
    else
        printf("%d is not a prime number.\n", number);

    return 0;
}
