#include "main.h"
/**
 * _printf - Fonction principal de l'execution de printf
 * @format: Chaine contenant le format a afficher.
 * Return: Nombre total à afficher
 */
int _printf(const char *format, ...) 
{
int i = 0, count = 0; 
va_list list;
check_h spec[] = {
{"c", print_char}, {"s", print_string}, {"%", print_perc},
{"d", print_deci}, {"i", print_deci}, {NULL, NULL},
};
va_start(list, format);
if (format == NULL) 
return (-1);
while (format[i] != '\0') 
{ 
if (format[i] == '%') {
i++;
int found = 0;
int j;
for (j = 0; spec[j].type; j++) 
{
if (format[i] == *spec[j].type) 
{
count += spec[j].func_print(list);
found = 1;
break;
}
}
if (!found) 
{
_putchar('%');
_putchar(format[i]);
count += 2;
}
} else {
_putchar(format[i]);
count++;
}
i++;
}
va_end(list);
return (count);
}