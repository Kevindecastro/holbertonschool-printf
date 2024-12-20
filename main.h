#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(const char *str);
int print_number(int n);

#endif
