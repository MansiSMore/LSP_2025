#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    int (*Add)(int, int);
    int (*Invalid)(int, int);
    char *error;

    handle = dlopen("./lib6_4.so", RTLD_LAZY);
    if (handle == NULL)
    {
        printf("Library load failed: %s\n", dlerror());
        return 1;
    }
    printf("Shared library loaded successfully.\n");

    dlerror();

    Add = (int (*)(int, int)) dlsym(handle, "Addition");
    error = dlerror();
    if (error == NULL)
    {
        printf("Addition function found.\n");
        printf("Addition Result = %d\n", Add(10, 5));
    }

    Invalid = (int (*)(int, int)) dlsym(handle, "Multiply");
    error = dlerror();
    if (error != NULL)
    {
        printf("Error fetching function 'Multiply': %s\n", error);
    }

    dlclose(handle);
    return 0;
}
