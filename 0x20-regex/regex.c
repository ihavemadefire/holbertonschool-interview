#include "regex.h"

/**
 * regex_match - checks whether given pattern matches a given string
 * @str: string to scan
 * @pattern: is the regular expression
 * Return: 1 if a "match", 0 if not.
 */
int regex_match(char const *str, char const *pattern)
{
	int temp = 0;

	if (*str == '\0' && *pattern == '\0')
		return (1);
	if ((*str == *pattern || *pattern == '.') && *(pattern + 1) != '*')
		return (regex_match(str + 1, pattern + 1));
	if (*(pattern + 1) == '*')
	{
		if (*str != '\0' && (*str == *pattern || *pattern == '.'))
			temp = regex_match(str + 1, pattern);
		return (regex_match(str, pattern + 2) || temp);
	}
	return (0);
}