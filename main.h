#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 1024
#define (void)(x)



_printf(const char *format, ...);
int prin_char(va_list args_in_list, char buff[], int lags,
                int width, int get_precision, int size);
int _string(va_list args_in_list, char buff[],
                int lags, int width, int get_precision, int size);
int _binary(va_list args_in_list, char buff[],
        int lags, int width, int get_precision, int size);
int _int(va_list args_in_list, char buff[],
        int custom_lags, int width, int get_precision, int custom_size);
void prin_buff(char buff, int *buf);

#endif
