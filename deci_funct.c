#include "main.h"

/**
 * print_deci - Fonction Affiche un décimal.
 * @list: la liste qui contient les arguments a passer.
 * Return: Nombre de caratère affichér.
 */
int print_deci(va_list list)
{
int n = va_arg(list, int);
unsigned int num = (n < 0) ? -n : n;
int count = 0;
if (n < 0)
{
_putchar('-');
count++;
}
if (num == 0)
{
_putchar('0');
return (count + 1);
}
char buffer[10];
int i = 0;
while (num)
{
buffer[i++] = (num % 10) + '0';
num /= 10;
}
while (--i >= 0)
{
_putchar(buffer[i]);
count++;
}
return (count);
}
