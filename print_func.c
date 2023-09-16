#include "main.h"

/**
 * _putchar - print character
 *
 * @c: the character
 *
 * Return: char
*/
int _putchar(int c)
{
	static int i;
	static char buff[BUFF_SIZE];

	i = 0;
	buff[i++] = c;
	if (i == BUFF_SIZE || c == '\n')
	{
		write(1, buff, i);
		i = 0;
	}
	return (c);
}

/**
 * _putss - print string
 *
 * @s: string
 *
 * Return: integer
*/

int _putss(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		_putchar(*s);
		s++;
		count++;
	}
	return (count);
}

/**
 * print_integer - function to print integer
 *
 * @n: number
 *
 * Return: integer
*/

int print_integer(int n)
{
	unsigned int num = n;
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
		count++;
	}
	if ((num / 10) > 0)
		count += print_integer(num / 10);
	_putchar((num % 10) + '0');
	count++;
	return (count);
}

/**
 * print_rev - functuin to print in reverse
 *
 * @s: string
 *
 * Return: nothing
*/

void print_rev(const char *s)
{
	int len;
	int i;

	if (s == NULL)
	{
		_putchar('%');
		_putchar('r');
		return;
	}
	len = strlen(s);
	for (i = len - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}

/**
 * rot13_string - function print string in reverse
 *
 * @s: string
 *
 * Return: nothing
*/

void rot13_string(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
		{
			if (s[i] >= 'a' && s[i] <= 'm')
				s[i] += 13;
			else if (s[i] >= 'A' && s[i] <= 'M')
				s[i] += 13;
			else if (s[i] >= 'n' && s[i] <= 'z')
				s[i] -= 13;
			else if (s[i] >= 'N' && s[i] <= 'Z')
				s[i] -= 13;
		}
	}
}
