#include "main.h"

/**
 *get_spec - finds function format
 *@s: the format string
 *pa: parameter struct
 *
 *Return: the number of bytes printed
 */

int (*get_spec(char *s))(va_list arg, p_t *pa)
{
	specifier_t specifiers[] = {
		{"c", character},
		{"d", integer},
		{"i", integer},
		{"s", string},
		{"%", percent},
		{"b", binary},
		{"o", octal},
		{"u", unsigned_number},
		{"x", hex},
		{"X", HEX},
		{"p", address},
		{"S", print_S},
		{"r", print_rev},
		{"R", rot13_string},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 *get_print_func - finds function format
 *@s: the format string
 *@arg: argument
 *@pa: parameter struct
 *
 *Return: the number of bytes printed
 */

int get_print_func(char *s, va_list arg, p_t *pa)
{
	int (*f)(va_list, p_t *) = get_spec(s);

	if (f)
		return (f(arg, pa));
	return (0);
}

/**
 *flag - finds flags
 *@s: the format string
 *@pa: parameter struct
 *
 *Return: the number of bytes printed
 */

int flag(char *s, p_t *pa)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = pa->f_plus = 1;
			break;
		case ' ':
			i = pa->f_space = 1;
			break;
		case '#':
			i = pa->f_hash = 1;
			break;
		case '-':
			i = pa->f_minus = 1;
			break;
		case '0':
			i = pa->f_zero = 1;
			break;
	}
	return (i);
}

/**
 *modifier - finds modifier
 *@s: the format string
 *@pa: parameter struct
 *
 *Return: the number of bytes printed
 */

int modifier(char *s, p_t *pa)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = pa->h_modif = 1;
			break;
		case 'l':
			i = pa->l_modif = 1;
			break;
	}
	return (i);
}

/**
 *width - finds width
 *@s: the format string
 *@pa: parameter struct
 *@arg: argument
 *
 *Return: new pointer
 */

char *width(char *s, p_t *pa, va_list arg)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(arg, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	pa->width = d;
	return (s);
}
