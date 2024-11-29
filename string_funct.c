#include "main.h"

/**
 * print_string - Function Affiche une chaine de caratères.
 * @list: la liste qui contient les arguments a passer.
 * Return: Nombre total.
 */
int print_string(va_list list)
{
char *str = va_arg(list, char *);
int count = 0;

if (str == NULL)  
str = "(null)";

   
while (*str)
{
_putchar(*str);
str++;
count++;
}

return (count);
}