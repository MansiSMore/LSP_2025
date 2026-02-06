#include <stdio.h>
#include <dlfcn.h>
int main()
{
    void *handle;
    void (*func)();
    char *error;

    /* Load library without full path */
    handle = dlopen("lib6_6.so", RTLD_LAZY);
    if (!handle)
    {
        printf("dlopen failed: %s\n", dlerror());
        return 1;
    }

    func = (void (*)()) dlsym(handle, "Display");
    error = dlerror();
    if (error != NULL)
    {
        printf("dlsym error: %s\n", error);
        dlclose(handle);
        return 1;
    }

    func();
    dlclose(handle);
    return 0;
}
