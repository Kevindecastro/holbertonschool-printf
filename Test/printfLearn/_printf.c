#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, len = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++; 
            switch (format[i])
            {
            case 'c':
                len += print_char(va_arg(args, int));
                break;
            case 's':
                len += print_string(va_arg(args, char *));
                break;
            case 'd':
            case 'i':
                len += print_int(va_arg(args, int));
                break;
            case 'u':
                len += print_unsigned(va_arg(args, unsigned int));
                break;
            case 'o':
                len += print_octal(va_arg(args, unsigned int));
                break;
            case 'x':
                len += print_hex(va_arg(args, unsigned int), 0);
                break;
            case 'X':
                len += print_hex(va_arg(args, unsigned int), 1);
                break;
            case 'p':
                len += print_pointer(va_arg(args, void *));
                break;
            case '%':
                len += print_char('%');
                break;
            case 'r':                     
                len += write(1, "%r", 2); 
                break;
            default:                   
                len += write(1, "r", 1); 
                if (format[i])           
                    len += print_char(format[i]);
                break;
            }
        }
        else
        {
            len += write(1, &format[i], 1); 
        }
        i++; 
    }

    va_end(args);
    return (len);
}
