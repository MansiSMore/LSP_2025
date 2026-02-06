#ifndef MYSTRING_H
#define MYSTRING_H

int  MyStrlen(const char *str);
void MyStrcpy(char *dest, const char *src);
void MyStrncpy(char *dest, const char *src, int n);
void MyStrcat(char *dest, const char *src);
int  MyStrcmp(const char *s1, const char *s2);
int  MyStrncmp(const char *s1, const char *s2, int n);
void MyStrrev(char *str);
char* MyStrchr(const char *str, char ch);

#endif
