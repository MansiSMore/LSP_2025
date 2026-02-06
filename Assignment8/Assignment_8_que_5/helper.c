#include "helper.h"

int Addition(int inum1, int inum2) {
    return inum1 + inum2;
}

int Subtraction(int inum1, int inum2) {
    return inum1 - inum2;
}

int Multiplication(int inum1, int inum2) {
    return inum1 * inum2;
}

int Division(int inum1, int inum2) {
    if (inum2 != 0) {
        return inum1 / inum2;
    }
    return 0;
}