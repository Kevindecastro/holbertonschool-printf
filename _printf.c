#include "main.h"
/**
 * _printf - Fonction principal de l'execution de printf
 * @format: Chaine contenant le format a afficher.
 * Return: Nombre total à afficher
 */
int _printf(const char *format, ...)
{
    /**Declare mes variables*/
    int i = 0, count = 0; 
    va_list list;

    /**Declare mes Specificateurs*/
    check_h spec[] = {
        {"c", print_char},
        {"s", print_string},
        {"%", print_perc},
        {"d", print_deci},
        {"i", print_deci},
        {NULL, NULL},
    };

    /** Initialisation de la list et condition Null */
    va_start(list, format);
    
    if (format == NULL) 
        return (-1);
    /** Parcours de la chaines */
    while (format[i] != '\0')
    { 
        if (format[i] == '%')
        {
            i++;
            int found = 0;
            int j;
            /** Itere chaque elements du tableau et compare le char apres % */
            for (j = 0; spec[j].type; j++)
            {
                if (format[i] == *spec[j].type)
                {
                    /** Imprime le nombre de char */
                    count += spec[j].func_print(list);
                    found = 1;
                    break;
                }
            }
        /** Si rien trouver */
            if (!found) {
                _putchar('%');
                _putchar(format[i]);
                /** Ajoute 2 au compteur pour les 2_putchar*/
                count += 2;
            }
        } else {
        /** Si rien on Incremente*/
            _putchar(format[i]);
            count++;
        }
        i++;
    }
/** Fin et liberations de l'espaces*/
    va_end(list);
    return (count);
    }