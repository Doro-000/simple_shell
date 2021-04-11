#include "shell_header.h"

/**
 * _strtok_r - tokenizes a string
 * @string: string to be tokenized
 * @delim: delimiter to be used to tokenize the string
 * @save_ptr: pointer to be used to keep track of the next token
 *
 * Return: The next available token
 */
char *_strtok_r (char *string, char *delim, char **save_ptr)
{
	char *end;

	if (string == NULL)
		string = *save_ptr;

	if (*string == '\0')
	{
		*save_ptr = string;
		return NULL;
	}

	string += strspn (string, delim);
	if (*string == '\0')
	{
		*save_ptr = string;
		return NULL;
	}

	end = string + strcspn (string, delim);
	if (*end == '\0')
	{
		*save_ptr = end;
		return string;
	}

	*end = '\0';
	*save_ptr = end + 1;
	return string;
}
