#include "shell_header.h"

/**
 * _strtok_r - tokenizes a string
 * @s: string to be tokenized
 * @delim: delimiter to be used to tokenize the string
 * @save_ptr: pointer to be used to keep track of the next token
 *
 * Return: The next available token
 */
char *_strtok_r (char *s, const char *delim, char **save_ptr)
{
	char *end;

	if (s == NULL)
		s = *save_ptr;

	if (*s == '\0')
	{
		*save_ptr = s;
		return NULL;
	}

	s += strspn (s, delim);
	if (*s == '\0')
	{
		*save_ptr = s;
		return NULL;
	}

	end = s + strcspn (s, delim);
	if (*end == '\0')
	{
		*save_ptr = end;
		return s;
	}

	*end = '\0';
	*save_ptr = end + 1;
	return s;
}
