#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle_lazy;
    void *handle_now;
    int (*InvalidFunc)(int, int);
    char *error;

    printf("Loading library using RTLD_LAZY...\n");
    handle_lazy = dlopen("./lib6_5.so", RTLD_LAZY);
    if (handle_lazy == NULL)
    {
        printf("RTLD_LAZY dlopen failed: %s\n", dlerror());
    }
    else
    {
        printf("RTLD_LAZY dlopen successful.\n");

        InvalidFunc = (int (*)(int,int)) dlsym(handle_lazy, "Multiplication");
        error = dlerror();
        if (error != NULL)
        {
            printf("RTLD_LAZY dlsym error: %s\n", error);
        }

        dlclose(handle_lazy);
    }

    printf("\nLoading library using RTLD_NOW...\n");
    handle_now = dlopen("./lib6_5.so", RTLD_NOW);
    if (handle_now == NULL)
    {
        printf("RTLD_NOW dlopen failed: %s\n", dlerror());
    }
    else
    {
        printf("RTLD_NOW dlopen successful.\n");
        dlclose(handle_now);
    }

    return 0;
}