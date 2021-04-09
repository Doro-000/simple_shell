#include "shell_header.h"

/**
 * tokenizer - tokenizes input and stores it into an array
 * @input: input to be parsed
 * @delim: delimiter to be used, needs to be one character string
 *
 * Return: array of tokens
 */
char **tokenizer(char *input, char *delim)
{
	int num_delim = 0, i = 0;
	char **av;
	char *token;

	for (; input[i] != '\0'; i++)
	{
		if (input[i] == delim[0])
			num_delim++;
	}
	i = 0;
	av = malloc(sizeof(*av) * (num_delim + 2));
	token = strtok(input, delim);
	while (token != NULL)
	{
		av[i] = remove_newline(token);
		token = strtok(NULL, delim);
		i++;
	}
	av[i] = NULL;
	return (av);
}

/**
 * print - prints a string to stdout
 * @string: string to be printed
 *
 * Return: void, return nothing
 */
void print(char *string)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
		write(1, string[i], 1);
}

/**
 * remove_newline - removes new line from a string
 * @str: string to be used
 *
 * Return: void
 */
void remove_newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}
