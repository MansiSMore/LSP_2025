#include "perfect.h"
#include "helper.h"

int IsPerfect(int inum)
{
    int sum = SumOfFactors(inum);

    if (sum == inum)
        return 1;
    else
        return 0;
}
