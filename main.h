#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

typedef struct vtype
{
    char tp;                        /* Type de spécificateur */
    void (*f)(va_list, char *, int *); /* Fonction correspondante */
} vtype_t;

/* Prototypes des fonctions */
int _printf(const char *format, ...);
void format_c(va_list valist, char *buffer, int *index);
void format_s(va_list valist, char *buffer, int *index);
void format_d(va_list valist, char *buffer, int *index);
void format_u(va_list valist, char *buffer, int *index);
void format_perc(va_list valist, char *buffer, int *index);
void _write_buffer(char *buffer, int *index);
void reset_buffer(char *buffer);

#endif /* MAIN_H */
