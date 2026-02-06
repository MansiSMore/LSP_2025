#include <stdio.h>
#include "mystring.h"

int main()
{
    char str[100];
    int len;

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    len = MyStrlen(str);

    printf("Length of string: %d\n", len);

    printf("Length of NULL string: %d\n", MyStrlen(NULL));

    return 0;
}

