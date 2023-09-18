#include "main.h"

/**
 *hex - print unsigned hex number in lower
 *@arg: argument
 *@pa: parameters struct
 *
 *Return: bytes printed
 */

int hex(va_list arg, p_t *pa)
{
	unsigned long l;
	int c = 0;
	char *s;

	if (pa->l_modif)
		l = (unsigned long)va_arg(arg, unsigned long);
	else if (pa->h_modif)
		l = (unsigned short int)va_arg(arg, unsigned int);
	else
		l = (unsigned int)va_arg(arg, unsigned int);
	s = conversion(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, pa);
	if (pa->f_hash && l)
	{
		*--s = 'x';
		*--s = '0';
	}
	pa->unsign = 1;
	return (c += print_formated_number(s, pa));
}

/**
 *HEX - print unsigned hex number in upper
 *@arg: argument
 *@pa: parameters struct
 *
 *Return: bytes printed
 */

int HEX(va_list arg, p_t *pa)
{
	unsigned long l;
	int c = 0;
	char *s;

	if (pa->l_modif)
		l = (unsigned long)va_arg(arg, unsigned long);
	else if (pa->h_modif)
		l = (unsigned short int)va_arg(arg, unsigned int);
	else
		l = (unsigned int)va_arg(arg, unsigned int);
	s = conversion(l, 16, CONVERT_UNSIGNED, pa);
	if (pa->f_hash && l)
	{
		*--s = 'X';
		*--s = '0';
	}
	pa->unsign = 1;
	return (c += print_formated_number(s, pa));
}

/**
 *binary - print unsigned pinary number
 *@arg: argument
 *@pa: parameters struct
 *
 *Return: bytes printed
 */

int binary(va_list arg, p_t *pa)
{
	unsigned int n = va_arg(arg, unsigned int);
	char *s = conversion(n, 2, CONVERT_UNSIGNED, pa);
	int c = 0;

	if (pa->f_hash && n)
		*--s = '0';
	pa->unsign = 1;
	return (c += print_formated_number(s, pa));
}

/**
 *octal - print unsigned octal number
 *@arg: argument
 *@pa: parameters struct
 *
 *Return: bytes printed
 */

int octal(va_list arg, p_t *pa)
{
	unsigned long l;
	char *s;
	int c = 0;

	if (pa->l_modif)
		l = (unsigned long)va_arg(arg, unsigned long);
	else if (pa->h_modif)
		l = (unsigned short int)va_arg(arg, unsigned int);
	else
		l = (unsigned int)va_arg(arg, unsigned int);
	s = conversion(l, 8, CONVERT_UNSIGNED, pa);
	if (pa->f_hash && l)
		*--s = '0';
	pa->unsign = 1;
	return (c += print_formated_number(s, pa));
}
