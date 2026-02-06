#include "mymath.h"

int MyPow(int inum1, int inum2)
{
    int res = 1;
    while (inum2-- > 0) res *= inum1;
    return res;
}

int MySqrt(int inum)
{
    int i = 1;
    while (i * i <= inum) i++;
    return i - 1;
}

int MyAbs(int inum)
{
    return (inum < 0) ? -inum : inum;
}

int MyMax(int inum1, int inum2)
{
    return (inum1 > inum2) ? inum1 : inum2;
}

int MyMin(int inum1, int inum2)
{
    return (inum1 < inum2) ? inum1 : inum2;
}

int MyFactorial(int inum)
{
    int fact = 1;
    while (inum > 0) fact *= inum--;
    return fact;
}

int MyGCD(int inum1, int inum2)
{
    while (inum2 != 0)
    {
        int t = inum2;
        inum2 = inum1 % inum2;
        inum1 = t;
    }
    return inum1;
}

int MyLCM(int inum1, int inum2)
{
    return (inum1 * inum2) / MyGCD(inum1, inum2);
}

