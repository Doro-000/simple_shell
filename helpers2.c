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

/**
 * _strcat - concatenates 2 strings
 * @destination: string to be concatenated to
 * @source: string to concatenate
 *
 * Return: address of the new_string
 */
char *_strcat(char *destination, char *source)
{
	char *new_string = NULL; 
	int len_dest = _strlen(destination);
	int len_source = _strlen(source);

	new_string = malloc(sizeof(*new_string) * (len_dest + len_source + 1));
	_strcpy(destination, new_string);
	_strcpy(source, new_string + len_dest);
	new_string[len_dest + len_source] = '\0';
	return (new_string);
}
