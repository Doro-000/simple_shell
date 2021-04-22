#include "shell_header.h"

char **commands = NULL;
char *line = NULL;
int status = 0;

/**
 * main - entry point, the main shell
 *
 * Return: 0 on success
 */
int main(void)
{
	char **current_command = NULL;
	int i, type_command = 0;
	size_t n = 0;

	signal(SIGINT, ctrl_c_handler);
	while (1)
	{
		non_interactive();
		print("$ ");
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
		remove_newline(line);
		commands = tokenizer(line, ";");
		for (i = 0; commands[i] != NULL; i++)
		{
			current_command = tokenizer(commands[i], " ");
			if (current_command[0] == NULL)
			{
				free(current_command);
				break;
			}
			type_command = parse_command(current_command[0]);
			initalizer(current_command, type_command);
			free(current_command);
		}
		free(commands);
	}
	free(line);
	return (status);
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
		{
			waitpid(child, &status, 0);
			status >>= 8;
		}
	}
	else
		execute_command(current_command, type_command);
}

/**
 * non_interactive - handles non_interactive mode
 *
 * Return: void
 */
void non_interactive(void)
{
	char **current_command = NULL;
	int i, type_command = 0;
	size_t n = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&line, &n, stdin) != -1)
		{
			remove_newline(line);
			commands = tokenizer(line, ";");
			for (i = 0; commands[i] != NULL; i++)
			{
				current_command = tokenizer(commands[i], " ");
				if (current_command[0] == NULL)
				{
					free(current_command);
					break;
				}
				type_command = parse_command(current_command[0]);
				initalizer(current_command, type_command);
				free(current_command);
			}
			free(commands);
		}
		free(line);
		exit(status);
	}
}
