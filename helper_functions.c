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
