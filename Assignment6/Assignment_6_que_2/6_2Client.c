#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    int (*Add)(int, int);
    char *error;

    handle = dlopen("./libmath.so", RTLD_LAZY);
    if (handle == NULL)
    {
        printf("dlopen failed: %s\n", dlerror());
        return 1;
    }

    /* Clear any existing errors */
    dlerror();

    /* Get address of function */
    Add = (int (*)(int, int)) dlsym(handle, "Addition");
    error = dlerror();
    if (error != NULL)
    {
        printf("dlsym failed: %s\n", error);
        dlclose(handle);
        return 1;
    }

    /* Call the function */
    printf("Addition Result = %d\n", Add(10, 20));

    /* Close the shared library */
    dlclose(handle);

    return 0;
}
//gcc 6_2Client.c -o client -ldl