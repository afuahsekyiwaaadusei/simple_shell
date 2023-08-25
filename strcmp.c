#include "main.h"




/**
 *_strcmp - a function that compares two strings.
 *@s1: first string.
 *@s2: second string.
 *
 *Return: zero if equal.
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, len1, len2;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	if (len1 == len2)
	{
		while (s1[i])
		{
			if (s1[i] != s2[i])
				return (-1);
			i++;
		}
		return (0);
	}
	return (-1);

}
