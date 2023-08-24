#include "monty.h"

/**
 * _strcmp - compares two strings
 *
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 *
 * Return: <true> if equal, <false> otherwise
 */
bool _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (false);
		i++;
	}

	if ((s1[i] == '\0' || s2[i] == '\n') || (s1[i] == '\n' || s2[i] == '\0'))
		return (true);

	return (false);
}
