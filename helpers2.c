#include "shell_header.h"

/**
 * _strcmp - comapres two strings
 * @first: first string to be comapred
 * @second: second string to be comapred
 *
 * Return: difference of the two strings
 */
int _strcmp(char *first, char *second)
{
	int i = 0;

	while(first[i] != '\0')
	{
		if (first[i] != second[i])
			break;
		i++;
	}
	return first[i] - second[i];
}
