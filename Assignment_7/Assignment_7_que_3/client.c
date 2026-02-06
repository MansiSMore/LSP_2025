#include <stdio.h>
#include "display.h"

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    Display(str);

    return 0;
}

