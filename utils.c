#include "shell_header.h"

/**
 * parse_command - decides the type of the command
 * @command: command to be parsed
 * 
 * Return: constant representing the type of the command
 * Description - EXTERNAL_COMMAND (1) represents commands like /bin/ls
 * 		 INTERNAL_COMMAND (2) represents commands like exit, env
 * 		 PATH_COMMAND (3) represents commands found in the PATH like ls
 *		 INVALID_COMMAND (-1) represents invalid commands
 */
int parse_command(char *command)
{
	int i;
	/*Add one to the index whenever you add a command*/
	char *internal_command[3] = {"env", "exit", NULL};
	char *path = NULL;

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
	if ((path = check_path(command)) != NULL)
	{
		return (PATH_COMMAND);
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
	else if (command == PATH_COMMAND)
	{
		tokenized_command[0] = check_path(tokenized_command[0]);
		execute_command(tokenized_command, EXTERNAL_COMMAND);
	}
	else if (command_type == INTERNAL_COMMAND)
	{
		func = get_func(tokenized_command[0]);
		func(tokenized_command);
	}
	else
		;
}

/**
 * check_path - checks if a command is found in the PATH
 * @command: command to be used
 *
 * Return: path where the command is found in, NULL if not found
 */
char *check_path(char *command)
{
	char **path_array = tokenizer(_getenv("PATH"), ":");
	char *temp;
	int i;

	for (i = 0; path_array[i] != NULL; i++)
	{
		temp = _strcat(path_array[i], "/");
		temp = _strcat(test, command);
		if (access(temp, F_OK) == 0)
			return (temp);
	}
	return (NULL);
}
