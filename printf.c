#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <stdint.h> 

/**
 * _printf: Function printf
 * @format: Chaine de caractere
 * Return: Always
 *  */


int _printf(const char *format, ...) {
    va_list args;
    int count = 0;
    int i;
    
    va_start(args, format);
    
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != '\0') {
            i++;
            switch (format[i]) {
                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    count += printf("%d", num);
                    break;
                }
                case 'u': {
                    unsigned int num = va_arg(args, unsigned int);
                    count += printf("%u", num);
                    break;
                }
                case 'o': {
                    unsigned int num = va_arg(args, unsigned int);
                    count += printf("%o", num);
                    break;
                }
                case 'x': {
                    unsigned int num = va_arg(args, unsigned int);
                    count += printf("%x", num);
                    break;
                }
                case 'X': {
                    unsigned int num = va_arg(args, unsigned int);
                    count += printf("%X", num);
                    break;
                }
                case 'p': {
                    uintptr_t addr = va_arg(args, uintptr_t);  
                    count += printf("0x%lx", addr);  
                    break;
                }
                case 'c': {
                    int ch = va_arg(args, int);
                    count += printf("%c", ch);
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    count += printf("%s", str);
                    break;
                }
                case '%': {
                    count += printf("%%");
                    break;
                }
                default:
                    count += printf("Unknown format specifier");
            }
        } else {
            putchar(format[i]);
            count++;
        }
    }

    va_end(args);
    return count;
}
