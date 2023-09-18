#include "main.h"

/**
 * print_range - function to check print range
 *
 * @start: start
 *
 * @stop: end
 *
 * @except: except
 *
 * Return: integer
*/

int print_range(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * percent - function to print percent
 *
 * @arg: arguments
 *
 * @pa: paramaters
 *
 * Return: integer
*/

int percent(va_list arg, p_t *pa)
{
	(void)arg;
	(void)pa;
	return (_putchar('%'));
}

/**
 * integer - function to print integer
 *
 * @arg: arguments
 *
 * @pa: parameters
 *
 * Return: integer
*/

int integer(va_list arg, p_t *pa)
{
	long l;

	if (pa->l_modif)
		l = va_arg(arg, long);
	else if (pa->h_modif)
		l = (short int)va_arg(arg, int);
	else
		l = (int)va_arg(arg, int);
	return (print_formated_number(conversion(l, 10, 0, pa), pa));
}
