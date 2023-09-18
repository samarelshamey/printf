#include "main.h"

/**
 * _putchar - print character
 *
 * @c: the character
 *
 * Return: integer
*/

int _putchar(int c)
{
	static int i;
	static char buff[BUFF_SIZE];

	if (c == BUFF_FLUSH || i >= BUFF_SIZE)
	{
		write(1, buff, i);
		i = 0;
	}
	if (c != BUFF_FLUSH)
		buff[i++] = c;
	return (1);
}
