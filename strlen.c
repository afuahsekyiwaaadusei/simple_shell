#include "main.h"


/**
 *_strlen - a function that gets the length of a string.
 *@str: string.
 *
 *Return: the length of @str.
 */

int _strlen(char *str)
{
	int i = 0;
	
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}
