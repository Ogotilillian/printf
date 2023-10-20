#ifndef _MAIHN_H
#define _MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024


int _printf(const char *format, ...);
int print_nairobi_string(va_list bingoo);
int print_mombasa_char(va_list bingoo);
int print_dodoma_percent(va_list bingoo);
int integer_specifier(va_list bingoo);
#endif
