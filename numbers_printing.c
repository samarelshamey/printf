#include "main.h"

/**
 * print_formated_number - prints number with options
 * @s: the base number as string
 * @pa: the parameter struct
 *
 * Return: chars printed
 */

int print_formated_number(char *s, p_t *pa)
{
	unsigned int i = _strlen(s);
	int negative = (!pa->unsign && *s == '-');

	if (!pa->precision && *s == '0' && !s[1])
		s = "";
	if (negative)
	{
		s++;
		i--;
	}
	if (pa->precision != UINT_MAX)
		while (i++ < pa->precision)
			*--s = '0';
	if (negative)
		*--s = '-';
	if (!pa->f_minus)
		return (right_shift(s, pa));
	else
		return (left_shift(s, pa));
}

/**
 *right_shift - prints number with option
 *@s: abase number as string
 *@pa: the params struct
 *
 * Return: chars printed
 */

int right_shift(char *s, p_t *pa)
{
	unsigned int n = 0, neg, neg2, i = _strlen(s);
	char pad_char = ' ';

	if (pa->f_zero && !pa->f_minus)
		pad_char = '0';
	neg = neg2 = (!pa->unsign && *s == '-');
	if (neg && i < pa->width && pad_char == '0' && !pa->f_minus)
		s++;
	else
		neg = 0;
	if ((pa->f_plus && !neg2) || (!pa->f_plus && pa->f_space && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (pa->f_plus && !neg2 && pad_char == '0' && !pa->unsign)
		n += _putchar('+');
	else if (!pa->f_plus && pa->f_space && !neg2 && !pa->unsign && pa->f_zero)
		n += _putchar(' ');
	while (i++ < pa->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (pa->f_plus && !neg2 && pad_char == ' ' && !pa->unsign)
		n += _putchar('+');
	else if (!pa->f_plus && pa->f_space && !neg2 && !pa->unsign && !pa->f_zero)
		n += _putchar(' ');
	n += _putss(s);
	return (n);
}

/**
 *left_shift - prints number with option
 *@s: abase number as string
 *@pa: the params struct
 *
 *Return: chars printed
 */

int left_shift(char *s, p_t *pa)
{
	unsigned int n = 0, neg, neg2, i = _strlen(s);
	char pad_char = ' ';

	if (pa->f_zero && !pa->f_minus)
		pad_char = '0';
	neg = neg2 = (!pa->unsign && *s == '-');
	if (neg && i < pa->width && pad_char == '0' && !pa->f_minus)
		s++;
	else
		neg = 0;
	if (pa->f_plus && !neg2 && !pa->unsign)
		n += _putchar('+'), i++;
	else if (pa->f_space && !neg2 && !pa->unsign)
		n += _putchar(' '), i++;
	n += _putss(s);
	while (i++ < pa->width)
		n += _putchar(pad_char);
	return (n);
}
