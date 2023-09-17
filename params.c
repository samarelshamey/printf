#include "main.h"

/**
 * init_params - clears struct fields and reset buf
 * @p: the parameters struct
 * @a: the argument pointer
 * 
 * return : void 
*/

void init_params(p_t *p, va_list a);
{
    p->unsign  = 0;

    p->f_plus      = 0;
    p->f_minus     = 0;
    p->f_space     = 0;
    p->f_zero      = 0;
    p->f_hash      = 0;

    p->width       = 0;
    p->precision   = UINT_MAX;
    p->h_modif     = 0;
    P->l_modif     = 0;

    (void)a;
}