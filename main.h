#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
void print_err(ssize_t n, char *str);
char *str_dup(char *str);
int get_arg_no(char *str);
extern char **environ;
char **_argv(char *line);
void start(char **line, size_t *n, char *buf, ssize_t *nread, ssize_t *nwrite);
/**
 *struct node - a struct to create a linked list of PATH.
 *@data: array of characters of each path.
 *@next: next node pointer.
 */
typedef struct node
{
	char data[120];
	struct node *next;
} node;
node *list(void);
char *which(char *av);
void print_err(ssize_t n, char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
char *_strcat(char *s1, char *s2);
#endif

