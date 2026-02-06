#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    int (*operation)(int, int);
    int choice, a, b;
    char *error;

    handle = dlopen("./libmath.so", RTLD_LAZY);
    if (handle == NULL)
    {
        printf("dlopen failed: %s\n", dlerror());
        return 1;
    }

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("\n1. Addition");
    printf("\n2. Substraction");
    printf("\n3. Multiplication");
    printf("\n4. Division");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    dlerror();   // Clear previous errors

    switch (choice)
    {
        case 1:
            operation = (int (*)(int, int)) dlsym(handle, "Addition");
            break;
        case 2:
            operation = (int (*)(int, int)) dlsym(handle, "Substraction");
            break;
        case 3:
            operation = (int (*)(int, int)) dlsym(handle, "Multiplication");
            break;
        case 4:
            operation = (int (*)(int, int)) dlsym(handle, "Division");
            break;
        default:
            printf("Invalid choice\n");
            dlclose(handle);
            return 0;
    }

    error = dlerror();
    if (error != NULL)
    {
        printf("dlsym error: %s\n", error);
        dlclose(handle);
        return 1;
    }

    printf("Result = %d\n", operation(a, b));

    dlclose(handle);
    return 0;
}

