#include <stdio.h>
#include <stdarg.h>
// Experiment of varibale argument input

int print(char *a, ...)
{
    va_list list;
    va_start(list, a);
    vprintf(a, list);
    va_end(list);
}

int main()
{
    print("Fuck you %d %d", 23, 56);
}