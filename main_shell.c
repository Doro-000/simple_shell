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
	char **commands = NULL;
	char **current_command = NULL;
	char *line = NULL;
	int i = 0, type_path = 0, a = 0;
	size_t n = 0;

	if (argc > 1)
	{
		while (argv[a] != 0)
		{
			current_command = tokenizer(command[i], " ");
			type_path = parse_command(current_command[0]);
			intializer(current_command, type_path);
			free(current_command);
			a++;
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
			current_command = tokenizer(command[i], " ");
			type_path = parse_command(current_command[0]);
			intializer(commands, pars);
		}
		free(commands);
	}
	free(line);
	return (0);
}

/**
 * intializer - starts the execution
 * @arg_tok: first checked input
 * @pars: type of command
 *
 * Return: Void function
 */
void intializer(char **arg_tok, int pars)
{
	pid_t child;

	if (pars == EXTERNAL_COMMAND || pars == PATH_COMMAND)
	{
		child = fork();
		if (child == 0)
			execute_command(arr, pars);
		else
			wait(NULL);
	}
	else
		execute_command(arr, pars);
}
