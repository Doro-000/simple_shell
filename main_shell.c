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
	int i, type_path = 0, a = 0;
	size_t n = 0;
	pid_t child;

	if (argc > 1)
	{
		for (i = 1; argv[i] != NULL; i++)
		{
			current_command = tokenizer(commands[i], " ");
			type_path = parse_command(current_command[0]);
			free(current_command);
		}
		return (0);
	}
	while (1)
	{
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
			type_path = parse_command(current_command[0]);
		}
		free(commands);
	}
	free(line);
	return (0);
}
