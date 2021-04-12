#include "shell_header.h"


/**
 * env - prints the current_environment
 * @tokenized_command - command entered
 *
 * Return: void
 * Description - tokenized_command is used here to make the function
 		comaptible for use in the function_map type, and hence is 
		ignored
 */
void env(char **tokenized_command __attribute__((unused)))
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		print(environ[i]);
}
