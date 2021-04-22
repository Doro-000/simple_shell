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
	{
		free(tokenized_command);
		free(line);
		free(commands);
		exit(status);
	}
	else if (num_token == 2)
	{
<<<<<<< HEAD
=======
		arg = _atoi(tokenized_command[1]);
>>>>>>> cc10b19fa46b8575930b7dd753abe1e60339fcd6
		free(line);
		free(tokenized_command);
		free(commands);
		if (execve(tokenized_command[0], tokenized_command, NULL) == -1)
		{
			perror(_getenv("PWD"));
			status = 2;
		}
	}
	else
		print("$: exit doesn't take more than one argument\n");
}
