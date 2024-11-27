#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/* Fonction utilitaire pour convertir un nombre en une base donnée */
void int_to_base(unsigned long num, int base, int is_upper, char *buffer)
{
    const char *digits = is_upper ? "0123456789ABCDEF" : "0123456789abcdef";
    char temp[64];
    int i = 0;

    if (num == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }

    while (num > 0)
    {
        temp[i++] = digits[num % base];
        num /= base;
    }

    for (int j = 0; j < i; j++)
        buffer[j] = temp[i - j - 1];

    buffer[i] = '\0';
}


int _printf(const char *format, ...)
{
    int len = 0; 
    va_list arg_list;
    va_start(arg_list, format);

    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%') 
        {
            i++; 
            switch (format[i])
            {
            case 's': 
            {
                char *str = va_arg(arg_list, char *);
                if (!str)
                    str = "(null)";

                for (int j = 0; str[j] != '\0'; j++, len++)
                    putchar(str[j]);
                break;
            }
            case 'c': 
            {
                char c = (char)va_arg(arg_list, int);
                putchar(c);
                len++;
                break;
            }
            case 'd': 
            case 'i':
            {
                int num = va_arg(arg_list, int);
                char buffer[32];
                if (num < 0)
                {
                    putchar('-');
                    len++;
                    num = -num;
                }
                int_to_base(num, 10, 0, buffer);
                for (int j = 0; buffer[j] != '\0'; j++, len++)
                    putchar(buffer[j]);
                break;
            }
            case 'u': 
            {
                unsigned int num = va_arg(arg_list, unsigned int);
                char buffer[32];
                int_to_base(num, 10, 0, buffer);
                for (int j = 0; buffer[j] != '\0'; j++, len++)
                    putchar(buffer[j]);
                break;
            }
            case 'o': 
            {
                unsigned int num = va_arg(arg_list, unsigned int);
                char buffer[32];
                int_to_base(num, 8, 0, buffer);
                for (int j = 0; buffer[j] != '\0'; j++, len++)
                    putchar(buffer[j]);
                break;
            }
            case 'x': 
            {
                unsigned int num = va_arg(arg_list, unsigned int);
                char buffer[32];
                int_to_base(num, 16, 0, buffer);
                for (int j = 0; buffer[j] != '\0'; j++, len++)
                    putchar(buffer[j]);
                break;
            }
            case 'X': 
            {
                unsigned int num = va_arg(arg_list, unsigned int);
                char buffer[32];
                int_to_base(num, 16, 1, buffer);
                for (int j = 0; buffer[j] != '\0'; j++, len++)
                    putchar(buffer[j]);
                break;
            }
            case 'p': 
            {
                void *ptr = va_arg(arg_list, void *);
                unsigned long addr = (unsigned long)ptr;
                char buffer[32];
                int_to_base(addr, 16, 0, buffer);

                putchar('0');
                putchar('x');
                len += 2;

                for (int j = 0; buffer[j] != '\0'; j++, len++)
                    putchar(buffer[j]);
                break;
            }
            case '%': 
            {
                putchar('%');
                len++;
                break;
            }
            default: 
            {
                putchar('%');
                putchar(format[i]);
                len += 2;
                break;
            }
            }
        }
        else
        {
            putchar(format[i]);
            len++;
        }
    }

    va_end(arg_list);
    return len;
}
