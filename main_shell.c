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
	char *line = NULL;
	int i = 0;
	size_t n = 0;

	if (argc > 1)
	{
		while (argv[i] != 0)
		{
			intializer(argv);
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
		intializer(commands, pars);
		free(commands);
	}
	free(line);
	return (0);
}

/**
 * intializer - starts the execution
 * @arg_tok: first checked input
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
