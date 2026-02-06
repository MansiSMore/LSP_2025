#include <stdio.h>

// Global variable inside shared library to demonstrate persistence across function calls
int gCounter = 0;

// Modify global variable 
void Increment()
{
    gCounter++;
}

// Display global variable 
void Display()
{
    printf("Current value of gCounter = %d\n", gCounter);
}

// Reset global variable to demonstrate that changes persist across function calls 
void Reset()
{
    gCounter = 0;
}
