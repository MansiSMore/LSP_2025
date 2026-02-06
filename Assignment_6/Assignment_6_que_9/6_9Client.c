#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    int (*func[3])(int, int);   
    char *names[] = {"Addition", "Substraction", "Multiplication"};
    char *error;
    int icnt;

    handle = dlopen("./lib6_9.so", RTLD_LAZY);
    if (!handle)
    {
        printf("dlopen failed: %s\n", dlerror());
        return 1;
    }

    dlerror();  
    
    for (icnt = 0; icnt < 3; icnt++)
    {
        func[icnt] = (int (*)(int, int)) dlsym(handle, names[icnt]);
        error = dlerror();
        if (error != NULL)
        {
            printf("dlsym error: %s\n", error);
            dlclose(handle);
            return 1;
        }
    }

    
    for (icnt = 0; icnt < 3; icnt++)
    {
        printf("Function: %s\n", names[icnt]);
        printf("Address : %p\n", func[icnt]);
        printf("Result  : %d\n\n", func[icnt](10, 5));
    }

    dlclose(handle);
    return 0;
}

