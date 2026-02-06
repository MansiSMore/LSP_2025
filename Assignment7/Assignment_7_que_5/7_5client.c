#include <stdio.h>
#include "mystring.h"
#include "mymath.h"

int main()
{
    int choice;
    char str1[100], str2[100];
    int a, b;

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. String Length\n2. String Copy\n3. String Compare\n");
        printf("4. Power\n5. Square Root\n6. Factorial\n");
        printf("7. GCD\n8. LCM\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                printf("Enter string: ");
                scanf("%[^\n]", str1);
                printf("Length = %d\n", MyStrlen(str1));
                break;

            case 2:
                printf("Enter source: ");
                scanf("%[^\n]", str1);
                MyStrcpy(str2, str1);
                printf("Copied string: %s\n", str2);
                break;

            case 3:
                printf("Enter string1: ");
                scanf("%[^\n]", str1);
                getchar();
                printf("Enter string2: ");
                scanf("%[^\n]", str2);
                printf("Compare result = %d\n", MyStrcmp(str1, str2));
                break;

            case 4:
                printf("Enter a b: ");
                scanf("%d %d", &a, &b);
                printf("Power = %d\n", MyPow(a, b));
                break;

            case 5:
                printf("Enter number: ");
                scanf("%d", &a);
                printf("Sqrt = %d\n", MySqrt(a));
                break;

            case 6:
                printf("Enter number: ");
                scanf("%d", &a);
                printf("Factorial = %d\n", MyFactorial(a));
                break;

            case 7:
                printf("Enter a b: ");
                scanf("%d %d", &a, &b);
                printf("GCD = %d\n", MyGCD(a, b));
                break;

            case 8:
                printf("Enter a b: ");
                scanf("%d %d", &a, &b);
                printf("LCM = %d\n", MyLCM(a, b));
                break;

            case 0:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

