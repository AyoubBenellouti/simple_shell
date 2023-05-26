#include "shell.h"

/**
*(alx peer project) interactive - returns true if shell is interactive mode
*(alx peer project) @info: struct address
*(alx peer project) Return: 1 if interactive mode, 0 otherwise
*/
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
*(alx peer project) is_delim - checks if character is a delimeter
*(alx peer project) @c: the char to check
*(alx peer project) @delim: the delimeter string
*(alx peer project) Return: 1 if true, 0 if false
*/
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
*(alx peer project) _isalpha - checks for alphabetic character
*(alx peer project) @c: The character to input
*(alx peer project) Return: 1 if c is alphabetic, 0 otherwise
*/

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
*(alx peer project) _atoi - converts a string to an integer
*(alx peer project)s: the string to be converted
*(alx peer project) =>  Return: 0 if no numbers in string, converted number otherwise
*/

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

