#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    int (*CountLower)(char *);
    int (*CountUpper)(char *);
    int (*CountDigit)(char *);
    char str[100];
    char *error;

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    handle = dlopen("./lib6_8.so", RTLD_LAZY);
    if (!handle)
    {
        printf("dlopen failed: %s\n", dlerror());
        return 1;
    }

    dlerror();   

    CountLower = (int (*)(char *)) dlsym(handle, "CountLower");
    CountUpper = (int (*)(char *)) dlsym(handle, "CountUpper");
    CountDigit = (int (*)(char *)) dlsym(handle, "CountDigit");

    error = dlerror();
    if (error != NULL)
    {
        printf("dlsym error: %s\n", error);
        dlclose(handle);
        return 1;
    }

    printf("Lowercase letters : %d\n", CountLower(str));
    printf("Uppercase letters : %d\n", CountUpper(str));
    printf("Digits            : %d\n", CountDigit(str));

    dlclose(handle);
    return 0;
}
