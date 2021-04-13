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
	char **commands = NULL;
	char **current_command = NULL;
	char *line = NULL;
	size_t n = 0;
	int i, type_command;
	pid_t child;

	while (1)
	{
		print("$ ");
		if (getline(&line, &n, stdin) == -1)
			exit(EXIT_SUCCESS);
		commands = tokenizer(line, ";");
		for (i = 0; commands[i] != NULL; i++)
		{
			current_command = tokenizer(commands[i], " ");
			type_command = parse_command(current_command[0]);
			if (type_command == EXTERNAL_COMMAND || type_command == PATH_COMMAND)
			{
				child = fork();
				if (child == 0)
					execute_command(current_command, type_command);
				else
					wait(NULL);
			}
			else
				execute_command(current_command, type_command);
		}
	}
	free(line);
	return (0);
}
