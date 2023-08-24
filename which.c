#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
char *check(char *cwd);

/**
 *which - a function that looks for files in the current PATH.
 *@av: file.
 *
 *Return: the path of the file. 
 */

char *which(char *av)
{
	int j = 0;
	char *PATH = getenv("PATH"), *cwd;
	struct stat st;
	node *node;
	
	cwd = check(cwd);
	printf("%s\n", cwd);
	if (!cwd)
		perror("cwd");
	if (stat(av, &st) == 0)
		return(av);
	else
	{
		node = list();
		while (node != NULL)
		{
			j = chdir(node->data);
			print_err(j, "chdir");
			if (stat(av, &st) == 0)
			{
				j = chdir(cwd);
				print_err(j, "chdir");
				return(node ->data);
			}
			node  = node->next;
		}
	}
	j = chdir(cwd);
	print_err(j, "chdir");
	return (NULL);
}


/**
 *check - used to check the return value of getcwd
 *and reallocate memory if Errange error is encountered.
 *@cwd : string pointer.
 *
 *Return: current working directory.
 */
char *check(char *cwd)
{
	size_t size = 120;
	char *buf = NULL;
	while (1)
	{
		buf = (char *)realloc(buf, size);
		if (buf == NULL) 
		{
			perror("realloc");
			return (0);
		}
		cwd = getcwd(buf, size);
		if (cwd != NULL)
		{
			free(buf);
			return (cwd);
		}
		else
		{
			if (errno == ERANGE)
			{
				size *= 2;
			}
			else
			{
				perror("getcwd");
				free(buf);
				return (0);
			}
		}
	}
	return (NULL);
}
