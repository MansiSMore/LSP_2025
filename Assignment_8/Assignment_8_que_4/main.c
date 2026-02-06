#include <stdio.h>
#include "helper.h"

int main() {
    int inum1, inum2;
    printf("Enter two numbers: ");
    scanf("%d %d", &inum1, &inum2);
    int isum = Addition(inum1, inum2);
    printf("Sum: %d\n", isum);
    return 0;
}