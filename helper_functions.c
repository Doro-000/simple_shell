#include "shell_header.h"

void print(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		write(1, string[i], 1);
		i++;
	}
}
