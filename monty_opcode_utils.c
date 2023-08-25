#include "monty.h"

/**
 * _strcmp - compares two strings
 *
 * @s1: pointer to the first str representing the valid opcode
 * @s2: pointer to the second str representing the given opcode
 *
 * Return: <true> if equal, <false> otherwise
 */
bool _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1++ != *s2++)
			return (false);
	}

	if (*s2 == '\0' || *s2 == '\n')
		return (true);

	return (false);
}

/**
 * is_valid_int - checks whether a string can be converted
 * to a valid integer or not
 *
 * @str: the string to be checked
 *
 * Return: <true> is the string can be converted, <false> otherwise
 */
bool _is_valid_int(char *str)
{
	if (str == NULL || !(*str))
		return (false);

	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || *str == '-' || *str == '\n')
		{
			str++;
			continue;
		}
		return (false);
	}

	return (true);
}
