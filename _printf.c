#include "main.h"
#include <unistd.h>

/**
* hand_spec - Spécificateur a gerer
* @specifier: Spec a utiliser
* @args: Arguments
* Return: Nombre de caractères imprimés
*/
int hand_spec(char specifier, va_list args);

/**
* _printf - Fonction principale printf
* @format: Chaine de caractères contenant un format specifier
* Return: Nombre de caractères.
*/
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_specifiers(format[i], args);
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}

	va_end(args);
	return (count);
}

/**
* hand_spec - Spécificateur a gerer
* @specifier: Spec a utiliser
* @args: Arguments
* Return: Nombre de caractères imprimés
*/
int hand_spec(char specifier, va_list args)
{
	int count = 0;

	switch (specifier)
	{
	case 'c':
		count += print_char(va_arg(args, int));
		break;
	case 's':
		count += print_string(va_arg(args, char *));
		break;
	case '%':
		count += print_char('%');
		break;
	case 'd':
	case 'i':
		count += print_number(va_arg(args, int));
		break;
	default:
		count += write(1, "%", 1);
		count += write(1, &specifier, 1);
		break;
	}

	return (count);
}
