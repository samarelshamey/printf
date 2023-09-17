#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

#define BUFF_SIZE 1024

#define NULL_STRING "(null)"

/*flags*/
#define F_PLUS 2
#define F_MINUS 1
#define F_SPACE 16
#define F_HASH 8
#define F_ZERO 4
#define P_INIT (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

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
	unsigned int unsign	: 1;

	unsigned int f_plus;	: 1;
	unsigned int f_minus;	: 1;
	unsigned int f_space;	: 1;
	unsigned int f_zero;	: 1;
	unsigned int f_hash;	: 1;

	unsigned int width;	: 1;
	unsigned int precision;	: 1;

	unsigned int h_modif;	: 1;
	unsigned int l_modif;	: 1;
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
	int (*p)(va_list, p_t *);
} spec_t;

/*print string*/
int _putss(char *s);
/*print character*/
int _putchar(int c);
/*print integer*/
int print_integer(int n);
/*print srting in reverse*/
void print_rev(const char *s);
/*print in rot13*/
int rot13_string(va_list a, p_t *p);
/*initiate parameters*/
void p_initiate(p_t *p, va_list pa);
/*get_flags*/
int get_flags(const char *format, int *i);
/*printf*/
int _printf(const char *format, ...);

#endif
