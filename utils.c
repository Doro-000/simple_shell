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
	char *internal_command[] = {"env", "exit", NULL};
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
		return (PATH_COMMAND);

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
			perror("$");
	}
	else if (command_type == PATH_COMMAND)
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
		print("$: Command not found\n"); /*need to be printed to stderr*/
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
		temp = _strcat(temp, command);
		if (access(temp, F_OK) == 0)
			return (temp);
	}
	return (NULL);
}

/**
 * get_func - retrives a function based on the command given and a mapping
 * @command: string to check against the mapping
 *
 * Return: pointer to the proper function, or null on fail
 */
void (*get_func(char *command))(char **)
{
	int i;
	function_map mapping[] = {
		{"env", env}, {"exit", quit}
	};

	for (i = 0; i < 2; i++)
	{
		if (_strcmp(command, mapping[i].command_name) == 0)
			return (mapping[i].func);
	}
	return (NULL);
}

/**
 * _getenv - gets the value of an environment variable from the environment list
 * @name: name of the environment variable
 *
 * Return: the value of the variable as a string
 */
char *_getenv(char *name)
{
	int pairs = 0, i = 0, flag = 0;
	char **keys = NULL;
	char **values = NULL;
	char *token = NULL;
	char *saveptr = NULL;
	char *final_val = NULL;

	for (; environ[pairs] != NULL; pairs++)
		;
	keys = malloc(sizeof(*keys) * pairs);
	values = malloc(sizeof(*values)  * pairs);
	for (; environ[i] != NULL; i++)
	{
		token = _strtok_r(environ[i], "=", &saveptr);
		keys[i] = token;
		values[i] = saveptr;
	}
	for (i = 0; i < pairs; i++)
	{
		if (_strcmp(keys[i], name) == 0)
		{
			flag = 1;
			final_val = values[i];
			break;
		}
	}
	free(keys);
	free(values);
	if (flag)
		return (final_val);
	else
		return (NULL);
}
