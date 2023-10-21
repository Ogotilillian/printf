#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
int can_print_char(va_list args);
int should_print_string(va_list args);
int _strlen(const char *str);
int _printf(const char *format, ...);

#endif
