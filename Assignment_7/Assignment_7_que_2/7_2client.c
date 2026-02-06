#include <stdio.h>
#include "addition.h"
#include "substraction.h"

int main()
{
    int inum1, inum2;

    printf("Enter two numbers: ");
    scanf("%d %d", &inum1, &inum2);

    printf("Addition      : %d\n", Addition(inum1, inum2));
    printf("Substraction  : %d\n", Substraction(inum1, inum2));

    return 0;
}
