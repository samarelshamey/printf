#include "main.h"

/**
 * p_initiate -  function initiate parameters
 *
 * @pa: parameter pointer
 *
 * @arg: arguments
 *
 * Return: nothing
*/

void p_initiate(p_t *pa, va_list arg)
{
	pa->unsign = 0;

	pa->f_plus = 0;
	pa->f_minus = 0;
	pa->f_space = 0;
	pa->f_zero = 0;
	pa->f_hash = 0;

	pa->width = 0;
	pa->precision = UINT_MAX;

	pa->h_modif = 0;
	pa->l_modif = 0;

	(void)arg;
}
