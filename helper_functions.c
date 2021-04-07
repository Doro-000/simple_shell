#include "shell_header.h"

/**
 * print - prints a string to stdout
 * @string: string to be printed
 *
 * Return: void, return nothing
 */
void print(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		write(1, string[i], 1);
		i++;
	}
}

/**
 * parse_input - parses and tokenizes input from user
 * @input: input to be parsed
 * @av: array to store tokens of the input
 *
 * Return: an integer that describes the type of input, see shell_header.h
 */
int parse_input(char *input, char **av)
{
	int num_delim = 0, i = 0;
	char *token;

	while (input[i] != '\0')
	{
		if (input[i] == ' ')
			num_delim++;
		i++;
	}
	i = 0;
	av = malloc(sizeof(*av) * (num_delim + 2));
	token = strtok(input, " ");
	while (token != NULL)
	{
		av[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	av[i] = NULL;
	return (EXTERNAL_COMMAND);
	/*works only for commands with absoulte paths and/or arguments, like "/bin/ls -l"*/s
}

/**
 * clean_input - removes new line from a string
 * @str: string to be used
 *
 * Return: void
 */
void clean_input(char *str)
{
	int i = 0;

	while(str[i] != '\n')
	{
		i++;
	}
	str[i] = '\0';
}
