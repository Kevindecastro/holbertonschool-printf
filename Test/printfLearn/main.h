#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(const char *str);
int print_int(int n);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);
int print_pointer(void *ptr);

#endif /* MAIN_H */
