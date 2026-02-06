#include "helper.h"

int SumOfFactors(int No)
{
    int i, sum = 0;

    for (i = 1; i <= No / 2; i++)
    {
        if (No % i == 0)
            sum += i;
    }
    return sum;
}
