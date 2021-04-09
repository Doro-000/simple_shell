#include "shell_header.h"

/**
 * parse_command - decides what a command is
 * @command: command to be parsed
 * 
 * Return: constant representing what a command is
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
