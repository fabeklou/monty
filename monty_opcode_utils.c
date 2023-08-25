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
 * _is_valid_int - checks whether a string can be converted
 * to a valid integer or not
 *
 * @str: the string to be checked
 *
 * Return: <true> is the string can be converted, <false> otherwise
 */
bool _is_valid_int(char *str)
{
	if (str == NULL || !(*str) || str[0] == '\n')
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

/**
 * check_lastchar - checks whether the last character of a string
 * is the new line character or not
 *
 * @str: the string to be checked
 *
 * Return: <true> if the last is new line, <false> otherwise
 */
bool check_lastchar(char *str)
{
	unsigned int i = 0;

	if (str == NULL || !str[0])
		return (false);

	while (str[i])
		i++;

	if (str[i - 1] == '\n')
		return (true);
	return (false);
}
