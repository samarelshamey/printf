#include "main.h"

/**
 * _printf - function mimic printf
 *
 * @format: character
 *
 * Return: integer
*/

int _printf(const char *format, ...)
{
	int count = 0;
	va_list arg;

	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				count++;
				_putchar(va_arg(arg, int));
			}
			else if (*format == 's')
				count += _putss(va_arg(arg, char *));
			else if (*format == '%')
			{
				count++;
				_putchar('%');
			}
			else if (*format == 'd' || *format == 'i')
				count += print_integer(va_arg(arg, int));
			else
			{
				count += 2;
				_putchar('%');
				_putchar(*format);
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(arg);
	return (count);
}
