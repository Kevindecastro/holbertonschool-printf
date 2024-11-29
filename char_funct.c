#include "main.h"

/**
 * print_char - Fonction affiche un caractere.
 * @list: la liste qui contient les arguments a passer.
 * Return: 1(Succes).
 */

int print_char(va_list list)
{
    _putchar(va_arg(list, int));  
    return (1);  
}