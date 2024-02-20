#include <stdio.h>

int main() {
    float percentage;
    
    // Ask the user to input their percentage score
    printf("Enter the percentage obtained by the student: ");
    scanf("%f", &percentage);
    
    // Determine the division based on the percentage
    if (percentage >= 80) {
        printf("Division: Distinction\n");
    } else if (percentage >= 60) {
        printf("Division: First Division\n");
    } else if (percentage >= 50) {
        printf("Division: Second Division\n");
    } else if (percentage >= 40) {
        printf("Division: Third Division\n");
    } else {
        printf("Division: Fail\n");
    }
    
    return 0;
}
