#include "shell_header.h"

/**
 * main - entry point, the main shell
 * @argc: number of arguments passed to the shell
 * @argv: list of arguments passed to the shell
 * @env: list of environment variables available to the shell
 *
 * Return: 0 on success
 */
int main()
{
	char **commands, **current_command;
	char *line;
	size_t n;
	int i;
	pid_t child;

	while (1)
	{
		print("$ ");
		if (getline(&line, &n, stdin) == -1)
			break;
		commands = tokenizer(line, ";");
		for (i = 0; commands[i] != NULL; i++)
		{
			current_command = tokenizer(commands[i], " ");
			if ((child = fork()) == 0)
			{
				if (execve(current_command[0], current_command, NULL) == -1)
				{
					perror("$");
				}
			}
			else
				wait(NULL);
		}
	}
	free(line);
	return (0);
}
