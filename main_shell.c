#include "shell_header.h"

/**
 * main - entry point, the main shell
 * @argc: number of arguments passed to the shell
 * @argv: list of arguments passed to the shell
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char **commands = NULL, **current_command = NULL;
	char *line = NULL;
	int i, type_command = 0;
	size_t n = 0;

	while (1)
	{
		if ((!isatty(STDIN_FILENO)))
		{
			printf("argv");
			for (i = 1; argv[i] != NULL; i++)
			{
				commands = tokenizer(argv[i], ";");
				for (k = 0; commands[k] != NULL; k++)
				{
					current_command = tokenizer(commands[k], " ");
					type_command = parse_command(current_command[0]);
					initalizer(current_command, type_command);
					free(current_command);
				}
				free(commands);
			}
			return (0);
		}
		print("$ ");
		if (getline(&line, &n, stdin) == -1)
		{
			print("\n");
			exit(EXIT_SUCCESS);
		}
		commands = tokenizer(line, ";");
		for (i = 0; commands[i] != NULL; i++)
		{
			current_command = tokenizer(commands[i], " ");
			type_command = parse_command(current_command[0]);
			initalizer(current_command, type_command);
			free(current_command);
		}
		free(commands);
	}
	free(line);
	return (0);
}

/**
 * initalizer - starts exectuting everything xD
 * @current_command: try to check current token
 * @type_command: parse token
 *
 * Return: void function
 */

void initalizer(char **current_command, int type_command)
{
	pid_t child;

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
