#include <string.h>
#include "main.h"
#include <stdlib.h>

/**
 *get_arg_no - gets the number of arguemt from a string
 *@str: string
 *
 *Return: the number of arguements in string
 */

int get_arg_no(char *str)
{
	char *new_str;
	char *token;
	int i = 0;

	new_str = str_dup(str);
	token = strtok(new_str, " ");
	while (token)
	{
		i++;
		token = strtok(NULL, " ");
	}
	free(new_str);
	return (i);
}

