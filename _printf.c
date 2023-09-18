#include "main.h"

/**
 * _printf - function
 *
 * @format: format
 *
 * Return: integer
*/

int _printf(const char *format, ...)
{
	p_t pa = P_INIT;
	int count = 0;
	va_list arg;
	char *p, *start;

	va_start(arg, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		p_initiate(&pa, arg);
		if (*p != '%')
		{
			count += _putchar(*p);
			continue;
		}
		start = p;
		p++;

		while (flag(p, &pa))
		{
			p++;
		}
		p = width(p, &pa, arg);
		p = precision(p, &pa, arg);
		if (modifier(p, &pa))
			p++;
		if (!get_spec(p))
			count += print_range(start, p, pa.l_modif || pa.h_modif ? p - 1 : 0);
		else
			count += get_print_func(p, arg, &pa);
	}
	_putchar(BUFF_FLUSH);
	va_end(arg);
	return (count);
}
