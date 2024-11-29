#include "main.h"
#include <unistd.h>

/**
 * print_char - Function affiche un caractère
 * @c: Caractère à afficher
 * Return: Nombre de caractères à afficher
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - Function affiche une chaîne de caractères
 * @str: Contient la chaîne de caractères
 * Return: Nombre de caractères imprimés
 */
int print_string(const char *str)
{
	int i = 0;

	if (!str)
		str = "(null)";

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}

	return (i);
}

/**
 * print_number - Function affiche un entier
 * @n: Entier affiché
 * Return: Nombre de caractères imprimés
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += print_char('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += print_number(num / 10);

	count += print_char((num % 10) + '0');
	return (count);
}
