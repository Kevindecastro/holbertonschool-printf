#include "main.h"
#include <stdint.h>

/**
 * print_char - Affiche des caracteres
 * @c: Caracteres
 * Return: Always
 */
int print_char(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_string - Chaines de caractères
 * @str: Chaine de caracters str
 * Return: Len 
 */

int print_string(const char *str)
{
    int len = 0;

    if (!str)
        str = "(null)";
    while (*str)
        len += write(1, str++, 1);
    return (len);
}
/**
 * print_int - Function Affiche des Entiers
 * @n: - Est L'entier
 * Return: Len
 */
int print_int(int n)
{
    unsigned int num;
    int len = 0;

    if (n < 0)
    {
        len += print_char('-');
        num = -n;
    }
    else
    {
        num = n;
    }
    if (num / 10)
        len += print_int(num / 10);
    len += print_char((num % 10) + '0');
    return (len);
}

/**
 * print_unsigned - Function Affiche Entiers insignés
 * @n: Entiers unsigné (positif)
 * Return: Len
 */
int print_unsigned(unsigned int n)
{
    int len = 0;

    if (n / 10)
        len += print_unsigned(n / 10);
    len += print_char((n % 10) + '0');
    return (len);
}

/**
 * print_octal - Function Affiche un Nombre Octet
 * @n: Nombre Octet
 * Return: len
 */
int print_octal(unsigned int n)
{
    int len = 0;

    if (n / 8)
        len += print_octal(n / 8);
    len += print_char((n % 8) + '0');
    return (len);
}

/**
 * print_hex - Function  Affiche un nombre Hexadécimal
 * @n: Hexadécimale
 * @uppercase: Majuscule Minuscule
 * Return: Len
 */

int print_hex(unsigned int n, int uppercase)
{
    int len = 0;
    char c;

    if (n / 16)
        len += print_hex(n / 16, uppercase);
    c = (n % 16 < 10) ? (n % 16 + '0') : (n % 16 - 10 + (uppercase ? 'A' : 'a'));
    len += print_char(c);
    return (len);
}

/**
 * print_pointer - Function Affiche la valeur d'un pointer
 * @ptr: pointers ptr
 * Return: Len
 */
int print_pointer(void *ptr)
{
    uintptr_t addr = (uintptr_t)ptr; 
    int len = 0;
    int i = 0;

    if (!ptr)
        return (print_string("(nil)"));

    len += print_string("0x");

    for (i = (sizeof(addr) * 2) - 1; i >= 0; i--)
    {
        char hex_digit = (addr >> (i * 4)) & 0xF;
        if (len > 2 || hex_digit > 0) 
            len += print_char(hex_digit < 10 ? hex_digit + '0' : hex_digit - 10 + 'a');
    }

    return (len);
}
