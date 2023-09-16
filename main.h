#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

#define BUFF_SIZE 1024


/*flags*/
#define F_PLUS 2
#define F_MINUS 1
#define F_SPACE 16
#define F_HASH 8
#define F_ZERO 4

/*print string*/
int _putss(char *s);
/*print character*/
int _putchar(int c);
/*print integer*/
int print_integer(int n);
/*print srting in reverse*/
void print_rev(const char *s);
/*print in rot13*/
void rot13_string(char *s);
/*get_flags*/
int get_flags(const char *format, int *i);
/*printf*/
int _printf(const char *format, ...);

#endif
