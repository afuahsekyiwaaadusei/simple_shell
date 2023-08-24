#include <stdio.h>
#include <errno.h>


/**
 *print_err - prints the error message.
 *@n: return value of called function.
 *@str: string.
 */
void print_err(ssize_t n, char *str)
{
        if (n == -1 && errno != 0)
                perror(str);
}
