#include "main.h"

int _printf(const char *format, ...)
{
int i = 0;
int j = 0;    
int count = 0;
int found = 0;   
va_list list;
check_h spec[] = {
{"c", print_char}, 
{"s", print_string},
{"%", print_perc}, 
{"d", print_deci}, 
{"i", print_deci}, 
{NULL, NULL}
};
va_start(list, format);
if (format == NULL)
return (-1);
while (format[i] != '\0')
{
if (format[i] == '%')
{
i++;
found = 1;
while (spec[j].type)
{
if (*spec[j].type == format[i])
{
count += spec[j].func_print(list);
found = 0;
}
j++;
}
if (found == 1)
{
_putchar(format[i - 1]);
_putchar(format[i]);
count += 2;
}
}
else
{
_putchar(format[i]);
count++;
}
j = 0;
i++;
}
va_end(list);
return (count);
}
