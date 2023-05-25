#include "monshell.h"

/**
 * num_elem - checks for a number
 * Return: zero or one
 * @c: var
 **/
int num_elem(char *j)
{
	char *elem = j;

	if (j == NULL)
		return (0);
	if (*elem == '-')
		elem++;

	for (; *elem != '\0'; elem++)
	{
		if ((*elem < '0' || *elem > '9'))
		{
			return (0);
		}
	}
	return (1);
}
