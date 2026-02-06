#include "mystring.h"
#include<stddef.h>
int MyStrlen(const char *str)
{
    int i = 0;
    if (!str) return 0;
    while (str[i] != '\0') i++;
    return i;
}

void MyStrcpy(char *dest, const char *src)
{
    while ((*dest++ = *src++));
}

void MyStrncpy(char *dest, const char *src, int n)
{
    int i;
    for (i = 0; i < n && src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
}

void MyStrcat(char *dest, const char *src)
{
    while (*dest) dest++;
    while ((*dest++ = *src++));
}

int MyStrcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
        s1++, s2++;
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}

int MyStrncmp(const char *s1, const char *s2, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
            return s1[i] - s2[i];
    }
    return 0;
}

void MyStrrev(char *str)
{
    int i = 0, j = MyStrlen(str) - 1;
    char temp;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j--;
    }
}

char* MyStrchr(const char *str, char ch)
{
    while (*str)
    {
        if (*str == ch)
            return (char*)str;
        str++;
    }
    return NULL;
}
