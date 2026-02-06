#include <stdio.h>

int Addition(int inum1, int inum2)
{
    return inum1+inum2;
}

int Substraction(int inum1, int inum2)
{
    return inum1 - inum2;
}
/*
gcc -fPIC -shared -o libmath.so Assignment6_1.c
*/