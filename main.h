#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>

int _printf(const char *format, ...);
int print_number(int n);
int print_unsigned_number(unsigned int n);
int print_octal(unsigned int n);
int print_hexadecimal(unsigned int n, int uppercase);
int print_pointer(uintptr_t n);
int print_string(char *str);


int _printf(const char *format, ...);

#endif