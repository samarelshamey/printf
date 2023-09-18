#include "main.h"

/**
 * _putss - print string
 *
 * @s: string
 *
 * Return: integer
*/

int _putss(char *s)
{
	char *a = s;

	while (*s)
	{
		_putchar(*s++);
	}
	return (s - a);
}
