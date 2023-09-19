#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define BUFF_SIZE 1024
#define BUFF_FLUSH -1

#define CONVERT_LOWERCASE       1
#define CONVERT_UNSIGNED        2

#define S_NULL "(null)"

#define P_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 * struct parameters - struct
 *
 * @unsign: unsign
 * @f_plus: plus sign
 * @f_minus: minus sign
 * @f_space: space
 * @f_zero: zero
 * @f_hash: hashtag sign
 * @width: width specifier
 * @precision: precision specifier
 * @h_modif: if short modifier
 * @l_modif: if long modifier
*/

typedef struct parameters
{
	unsigned int unsign     : 1;

	unsigned int f_plus     : 1;
	unsigned int f_minus    : 1;
	unsigned int f_space    : 1;
	unsigned int f_zero     : 1;
	unsigned int f_hash     : 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modif    : 1;
	unsigned int l_modif    : 1;
} p_t;

/**
 * struct specifier - struct token
 *
 * @specifier: format token
 * @f: the function associated
*/
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, p_t *);
} specifier_t;

/*print_func*/
int _putss(char *s);
int _putchar(int c);
int print_rev(va_list arg, p_t *pa);
int rot13_string(va_list arg, p_t *pa);
int print_range(char *start, char *stop, char *except);
int character(va_list arg, p_t *pa);
int integer(va_list arg, p_t *pa);
int string(va_list arg, p_t *pa);
int percent(va_list arg, p_t *pa);
int print_S(va_list arg, p_t *pa);

/*p_initiate.c*/
void p_initiate(p_t *pa, va_list arg);

/*specifier.c*/
int (*get_spec(char *s))(va_list arg, p_t *pa);
int get_print_func(char *s, va_list arg, p_t *pa);
int flag(char *s, p_t *pa);
int modifier(char *s, p_t *pa);
char *width(char *s, p_t *pa, va_list arg);

/*convert_number.c*/
int hex(va_list arg, p_t *p);
int HEX(va_list arg, p_t *p);
int binary(va_list arg, p_t *p);
int octal(va_list arg, p_t *p);

/*numbers.c*/
char *conversion(long int num, int base, int flags, p_t *pa);
int unsigned_number(va_list arg, p_t *pa);
int address(va_list arg, p_t *pa);

/*numbers_printing.c*/
int print_formated_number(char *s, p_t *pa);
int right_shift(char *s, p_t *pa);
int left_shift(char *s, p_t *pa);

/*fields.c*/
char *precision(char *p, p_t *pa, va_list arg);

/*_isdigit.c*/
int _isdigit(int c);

/*_strlen*/
int _strlen(char *s);

/*_printf.c*/
int _printf(const char *format, ...);
#endif
