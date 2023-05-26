#include "shell.h"

/**
 *(alx peering project) _eputs - prints an input string
 *(alx peering project) @str: the string to be printed
 *(alx peering project) Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
return (1);
}

/**
 *(alx peering project) _putfd - writes the character c to given fd
 *(alx peering project) @c: The character to print
 *(alx peering project) @fd: The filedescriptor to write to
 *(alx peering project) Return: On success 1.
 *(alx peering project) On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *(alx peering project) _putsfd - prints an input string
 *(alx peering project) @str: the string to be printed
 *(alx peering project) @fd: the filedescriptor to write to
 *(alx peering project) Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

