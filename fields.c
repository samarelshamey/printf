#include "main.h"

/**
 * precision - function to check precision
 *
 * @p: pointer
 *
 * @pa: parameters
 *
 * @arg: arguments
 *
 * Return: pointer
*/

char *precision(char *p, p_t *pa, va_list arg)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(arg, int);
		p++;
	}
	else
	{
		while (isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	pa->precision = d;
	return (p);
}
