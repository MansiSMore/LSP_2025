#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    int (*Add)(int, int);
    int (*Sub)(int, int);

    handle = dlopen("./libmath.so", RTLD_LAZY);
    if (!handle)
    {
        printf("dlopen error: %s\n", dlerror());
        return 1;
    }

    Add = (int (*)(int, int)) dlsym(handle, "Addition");
    Sub = (int (*)(int, int)) dlsym(handle, "Substraction");

    if (dlerror() != NULL)
    {
        printf("dlsym error\n");
        return 1;
    }

    printf("Addition = %d\n", Add(10, 5));
    printf("Substraction = %d\n", Sub(10, 5));

    dlclose(handle);
    return 0;
}
//gcc 6_1Client.c -o client -ldl
