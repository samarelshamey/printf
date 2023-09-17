#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define BUFF_FLUSH -1

#define NULL_STRING "(null)"

#define P_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define convert_lowercase  1
#define convert_unsigned   2

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
	unsigned int unsign 	: 1;

	unsigned int f_plus 	: 1;
	unsigned int f_minus	: 1;
	unsigned int f_space	: 1;
	unsigned int f_zero 	: 1;
	unsigned int f_hash 	: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modif	: 1;
	unsigned int l_modif	: 1;
} p_t;

/**
 * strcut specif - struct
 *
 * @spec: specifier
 * @p: function pointer
*/

typedef struct specif
{
	char *spec;
	int (*f)(va_list, p_t *);
} spec_t;

/*_put*/
int _puts(char *str);
int _putchar(int c);

/*print_function*/
int print_char(va_list a, p_t *p);
int print_int(va_list a, p_t *p);
int print_string(va_list a, p_t *p);
int print_percent(va_list a,p_t *p);
int print_s(va_list a,p_t *p);

/*number*/
char *convert(long int num, int base, int flags, p_t *p)
int print_unsigned(va_list a, p_t *p);
int print_address(va_list a, p_t *p);

/*convert_number*/
int print_hex(va_list a, p_t *p);
int print_HEX(va_list a, p_t *p);
int print_octal(va_list a, p_t *p);
int print_binary(va_list a, p_t *p);

/*simple_printers*/
int rot13_string(va_list a, p_t *p);
int print_rev(va_list a, p_t *p);
int print_from_to(va_list a, p_t *p);

/*specifier*/
int *get_specifier(char *s, va_list a, p_t *p);
int get_flag(char *s, p_t *p);
int get_modifier(char *s, p_t *p);
int get_print_func(char *s, va_list a, p_t *p);
char *get_width(char *s, va_list a, p_t *p);

/*print_number*/
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, p_t *p);
int print_number_right_shift(char *str, p_t *p);
int print_number_left_shift(char *str, p_t *p);

/*params*/
void init_params(p_t *p, va_list a);

/*string_fields*/
char *get_precision(char *pre, p_t *p, va_list a);

/*printf*/
int _printf(const char *format, ...);

#endif