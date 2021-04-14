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
	size_t n = 0;
	int i = 1;

	if (argc > 1)
	{
		while (argv[i] != NULL)
		{
			intializer(argv);
			i++;
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
		intializer(commands);
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
void intializer(char **arg_tok)
{
	pid_t child;
	char **arr = NULL;
	int pars, a = 0;

	while (arg_tok[a] != NULL)
	{
		arr = tokenizer(*arg_tok, " ");
		pars = parse_command(*arr);
		if (pars == 1 || pars == 2 || pars == 4)
		{
			child = fork();
			if (child == 0)
			{
				execute_command(arr, pars);
			}
			else
				wait(NULL);
		}
		else
		{
			execute_command(arr, pars);
			free(arr);
		}
		a++;
	}
}
