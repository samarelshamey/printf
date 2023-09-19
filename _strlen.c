#include "main.h"

/**
 * _strlen - function
 *
 * @s: string
 *
 * Return: integer
*/

int _strlen(char *s)
{
	int i = 0;
	
	while (*s++)
		i++;
	return (i);
}
