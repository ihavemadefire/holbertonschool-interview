#include "holberton.h"

/**
 * wildcmp - recursive compare two strings with * as wildcard
 * @s1: normal string
 * @s2: string w/wildcard
 * Return: 1 if "match", else 0.
 */
int wildcmp(char *s1, char *s2)
{
	int temp = 0;

	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	if (*s2 == '*')
	{
		if (*s1 != '\0')
			temp = wildcmp(s1 + 1, s2);
		return (wildcmp(s1, s2 + 1) || temp);
	}
	return (0);
}
