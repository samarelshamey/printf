#include "main.h"

/**
 * conversion - convert function a clone
 * @num: number
 * @base: base
 * @flags: argument flags
 * @pa: parameter struct
 *
 * Return: string
 */

char *conversion(long int num, int base, int flags, p_t *pa)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)pa;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * unsigned_number - prints unsigned integer number
 * @arg: argument pointer
 * @pa: the parameters struct
 *
 * Return: bytes printed
 */

int unsigned_number(va_list arg, p_t *pa)
{
	unsigned long l;

	if (pa->l_modif)
		l = (unsigned long)va_arg(arg, unsigned long);
	else if (pa->h_modif)
		l = (unsigned short int)va_arg(arg, unsigned int);
	else
		l = (unsigned int)va_arg(arg, unsigned int);
	pa->unsign = 1;
	return (print_formated_number(conversion(l, 10, CONVERT_UNSIGNED, pa), pa));
}

/**
 * address - prints address
 * @arg: argument pointer
 * @pa: the parameters struct
 *
 *Return: bytes printed
 */

int address(va_list arg, p_t *pa)
{
	unsigned long int n = va_arg(arg, unsigned long int);
	char *s;

	if (!n)
		return (_putss("(nil)"));
	s = conversion(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, pa);
	*--s = 'x';
	*--s = '0';
	return (print_formated_number(s, pa));
}
