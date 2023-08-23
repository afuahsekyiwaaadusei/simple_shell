#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
void print_err(ssize_t n, char *str);
char *str_dup(char *str);
int get_arg_no(char *str);
char **_argv(char *line);
#endif

