#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    void (*Increment)();
    void (*Display)();
    void (*Reset)();
    char *error;

    handle = dlopen("./lib6_7.so", RTLD_LAZY);
    if (!handle)
    {
        printf("dlopen failed: %s\n", dlerror());
        return 1;
    }

    dlerror();  // Clear previous errors

    Increment = (void (*)()) dlsym(handle, "Increment");
    Display   = (void (*)()) dlsym(handle, "Display");
    Reset     = (void (*)()) dlsym(handle, "Reset");

    error = dlerror();
    if (error != NULL)
    {
        printf("dlsym error: %s\n", error);
        dlclose(handle);
        return 1;
    }

   
    Increment();
    Increment();
    Display();    

    Increment();
    Display();   
    Reset();
    Display();   
    dlclose(handle);
    return 0;
}