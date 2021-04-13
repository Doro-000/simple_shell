#include "shell_header.h"


/**
 * env - prints the current_environment
 * @tokenized_command: command entered
 *
 * Return: void
 */
void env(char **tokenized_command __attribute__((unused)))
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		print(environ[i]);
		print("\n");
	}
}

/**
 * quit - exits the shell
 * @tokenized_command: command entered
 *
 * Return: void
 */
void quit(char **tokenized_command)
{
	int num_token = 0;

	for (; tokenized_command[num_token] != NULL; num_token++)
		;
	if (num_token == 1)
		exit(EXIT_SUCCESS);
	else if (num_token == 2)
		exit(_atoi(tokenized_command[1]));
	else
		print("$: exit doesn't take more than one argument\n");
}
