#include <stdlib.h>


/**
 *str_dup - duplicates a string in a new memory location.
 *@str: original string.
 *
 *Return: the duplicate string.
 */

char *str_dup(char *str)
{
	char *new_str;
	char *cnt = str;
	int i = 0;

	while (*cnt)
	{
		cnt++;
		i++;
	}
	new_str = malloc(sizeof(char) * (i + 1));
	i = 0;
	cnt = str;
	while (*cnt)
	{
		*(new_str + i) = *cnt;
		cnt++;
		i++;
	}
	*(new_str + i) = '\0';
	return (new_str);
}

