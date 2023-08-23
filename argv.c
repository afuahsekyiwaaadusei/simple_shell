#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 *_argv - creates an array of pointers
 *@line: string to be broken into pointers.
 *
 *Return: an array of pointers
 */

char **_argv(char *line)
{
	char *token;
	size_t arg_count;
	int count = 0;
	char **argv;

	arg_count = get_arg_no(line);
	if (arg_count == 0)
	{
		exit(-1);
	}
	arg_count++;
	argv = malloc(sizeof(char *) * arg_count);
	token = strtok(line, " ");
	while (token)
	{
		argv[count] = token;
		token = strtok(NULL, " ");
		count++;
	}
	argv[count] = NULL;
	return (argv);
}

