#include "shell_header.h"

/**
 * main - entry point, the main shell
 * @argc: number of arguments passed to the shell
 * @argv: list of arguments passed to the shell
 * @env: list of environment variables passed to the shell
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[], char *env[])
{
	char *command = NULL;
	size_t size = 0;
	pid_t child;
	int error_num, type_of_input;
	char **av;

	/*Interactive mode*/
	while(1)
	{
		print("> "); /*Needs proper prompt*/
		getline(&command, &size, stdin);
		clean_input(command);
		/*input assumed to be a command with arguments*/
		av = tokenize_input(command);
		type_of_input = get_input(av[0]);

		if ((child = fork()) == 0)
		{
			if (type_of_input == EXTERNAL_COMMAND)/*/bin/ls, ls, ./some_program...*/
			{
				if (execve(av[0], av, NULL) == -1)
					perror("Error")
			}
			else if (type_of_input == INTERNAL_COMMAND)/*exit, env, cd ...*/
				; /*To be added*/
			else if (type_of_input == SPECIAL_COMMAND)/*CTRL-D, CTRL-C...*/
				;/*To be added*/
		}
		else
		{
			wait(NULL);
			free(av);
		}
	}
	free(command);
	return (0);
}
