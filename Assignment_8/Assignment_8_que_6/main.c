#include <stdio.h>
#include "helper.h"

int main() {
    int inum1, inum2;
    printf("Enter two numbers: ");
    scanf("%d %d", &inum1, &inum2);
    printf("Addition: %d\n", Addition(inum1, inum2));
    printf("Subtraction: %d\n", Subtraction(inum1, inum2));
    printf("Multiplication: %d\n", Multiplication(inum1, inum2));
    if (inum2 != 0) {
        printf("Division: %d\n", Division(inum1, inum2));
    } else {
        printf("Division: Division by zero\n");
    }
    return 0;
}