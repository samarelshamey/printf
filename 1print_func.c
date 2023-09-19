#include "main.h"

/**
 * print_rev - functuin to print in reverse
 *
 * @arg: argument
 *
 * @pa: parameters
 *
 * Return: integer
*/

int print_rev(va_list arg, p_t *pa)
{
	int len, i = 0;
	char *s = va_arg(arg, char *);
	(void)pa;

	if (s)
	{
		for (len = 0; *s; s++)
			len++;
		s--;
		for (; len > 0; len--, s--)
			i += _putchar(*s);
	}
	return (i);
}

/**
 * rot13_string - function print string in reverse
 *
 * @arg: argument
 *
 * @pa: parameters
 *
 * Return: integer
*/

int rot13_string(va_list arg, p_t *pa)
{
	int i, ind;
	int count = 0;
	char ar[] = "NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm";
	char *s = va_arg(arg, char *);
	(void)pa;

	i = 0;
	ind = 0;

	while (s[i])
	{
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
		{
			ind = s[i] - 65;
			count += _putchar(ar[ind]);
		}
		else
			count += _putchar(s[i]);
		i++;
	}
	return (count);
}

/**
 * character - function to print char
 *
 * @arg: arguments
 *
 * @pa: parameters
 *
 * Return: integer
*/

int character(va_list arg, p_t *pa)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(arg, int);

	if (pa->f_minus)
		sum += _putchar(ch);
	while (pad++ < pa->width)
		sum += _putchar(pad_char);
	if (!pa->f_minus)
		sum += _putchar(ch);
	return (sum);
}

/**
 * string - function to print string
 *
 * @arg: arguments
 *
 * @pa: parameters
 *
 * Return: integer
*/

int string(va_list arg, p_t *pa)
{
	char *s = va_arg(arg, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)pa;
	switch ((int)(!s))
		case 1:
			s = S_NULL;
	j = pad = _strlen(s);
	if (pa->precision < pad)
		j = pad = pa->precision;
	if (pa->f_minus)
	{
		if (pa->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*s);
		else
			sum += _putss(s);
	}
	while (j++ < pa->width)
		sum += _putchar(pad_char);
	if (!pa->f_minus)
	{
		if (pa->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*s++);
		else
			sum += _putss(s);
	}
	return (sum);
}

/**
 * print_S - print string
 *
 * @arg: arguments
 *
 * @pa: parameters
 *
 * Return: integer
*/
int print_S(va_list arg, p_t *pa)
{
	char *s = va_arg(arg, char *);
	char *hex;
	int sum = 0;

	if ((int)(!s))
		return (_putss(S_NULL));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = conversion(*s, 16, 0, pa);
			if (!hex[1])
				sum += _putchar('0');
			sum += _putss(hex);
		}
		else
		{
			sum += _putchar(*s);
		}
	}
	return (sum);
}
