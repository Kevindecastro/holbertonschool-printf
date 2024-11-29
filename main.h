#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/**
* struct checker -Strucure du checker pour les functions demander
* @type: Pointers du caractère string
* @func_print: Pointer de la function d'affichage
*/



typedef struct checker
{
	char *type;

	int (*func_print)(va_list list);
} check_h;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list list);
int print_string(va_list list);
int print_perc(va_list list);
int print_deci(va_list list);
#endif 