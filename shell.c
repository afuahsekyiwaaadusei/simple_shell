#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

/**
 *main - a program that prints "$ ",
 *wait for the user to enter a command, and executes it.
 *@ac: count of program arguments.
 *@av: array of program arguements.
 *@env: program environment.
 *
 *Return: always 0.
 */

int main(int ac, char **av, char **env)
{
	char *line = NULL, **argv, *dup_str, buf[] = "cisfun$ ";
	ssize_t nread, nwrite;
	size_t  n = 0;
	pid_t pid = -1;
	(void)ac;
	(void)av;


	start(&line, &n, buf, &nread, &nwrite);
	while (nread != -1)
	{
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';
		pid = fork();
		print_err(pid, "pid");
		if (pid == 0)
		{
			nread = -1;
			dup_str = str_dup(line);
			argv = _argv(dup_str);
			if (!argv[0])
				break;
			if ((execve(argv[0], argv, env)) == -1)
				perror(argv[0]);
		}
		else
		{
			wait(NULL);
			free(line);
			line = NULL;
			start(&line, &n, buf, &nread, &nwrite);

		}
	}
	free(line);
	if (pid == 0)
	{
		free(argv);
		free(dup_str);
	}
	return (0);
}



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



/**
 *start - determines wheter shell is in interactive or non interactive mode.
 *@line: buffer containing text read.
 *@n: size of buffer.
 *@buf: buffer containing text to write in interactive mode.
 *@nread: number of bytes read.
 *@nwrite: number of bytes written.
 */


void start(char **line, size_t *n, char *buf, ssize_t *nread, ssize_t *nwrite)
{
	if ((isatty(STDIN_FILENO)) != 1)
		(*nread) = getline(line, n, stdin);
	else
	{
		(*nwrite) = write(STDOUT_FILENO, buf, sizeof((buf)));
		print_err(*nwrite, "write");
		(*nread) = getline(line, n, stdin);
	}

}
