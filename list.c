#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 *list - a function that builds a linked list of the PATH directories.
 *
 *Return: a linked list of the PATH directories.
 */

node *list(void)
{
	char *env = getenv("PATH");
	int i = 0, x = 0, j = 1;
	node *first;
	node *new_node = malloc(sizeof(node));
	node *last = NULL;
	
	while (env[i])
	{
		if (last)
		{
			last->next = new_node;
		}
		if (env[i] == ':')
		{
			new_node->data[x] = '\0';
			if (j)
			{
				first = new_node;
				j = 0;
				last = first;
			}
			else
			{
				last = new_node;
			}
			new_node = malloc(sizeof(node));
			x = 0;
		}
		else
		{
			new_node->data[x] = env[i];
			x++;
		}
		i++;
	}
	new_node->next = NULL;
	return (first);
}
