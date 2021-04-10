#include "shell_header.h"

/**
 * parse_command - decides the type of the command
 * @command: command to be parsed
 * 
 * Return: constant representing the type of the command
 * Description - EXTERNAL_COMMAND (1) represents commands like ls, /bin/ls
 * 		 INTERNAL_COMMAND (2) represents commands like exit, env
 *		 INVALID_COMMAND (-1) represents invalid commands
 */
int parse_command(char *command)
{
	int i;
	/*Add one to the index whenever you add a command*/
	char *internal_command[3] = {"env", "exit", NULL};

	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] == '/')
			return (EXTERNAL_COMMAND);
	}
	for (i = 0; internal_command[i] != NULL; i++)
	{
		if (_strcmp(command, internal_command[i]) == 0)
			return (INTERNAL_COMMAND);
	}

	return (INVALID_COMMAND);
}

/**
 * execute_command - executes a command based on it's type
 * @tokenized_command: tokenized format of the command (/bin/ls -l /bin == {/bin/ls, -l...})
 * @command_type - type of the command
 *
 * Return: void
 */
void execute_command(char **tokenized_command, int command_type)
{
	void (*func)(char **command);
	if (command_type == EXTERNAL_COMMAND)
	{
		if (execve(tokenized_command[0], tokenized_command, NULL) == -1)
		{
			perror("$");
		}
	}
	if (command_type == INTERNAL_COMMAND)
	{
		func = get_func(tokenized_command[0]);
		func(tokenized_command);
	}
	if (command == INVALID_COMMAND)
	{
		;
	}
}
