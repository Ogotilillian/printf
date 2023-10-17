#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUF_SIZ 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1
/**
 * struct formatt - Structure for format and associated function
 *ant it will relate all files.
 * @formatt: The format to managed
 * @fn: The function associated herae.
 */
struct formatt
{
char formatt;
int (*fn)(va_list, char[], int, int, int, int);
};
typedef struct formatt fmt_t;
int _printf(const char *format, ...);
int custom_manage_print(const char *formatt, int *i,
va_list args_in_ilst, char buff[], int custom_lags,
int width, int get_precision, int custom_size);
int custom_print_char(va_list args_in_list, char buff[],
int custom_lags, int width, int get_precision, int custom_size);
int custom_print_string(va_list args_in_list, char buff[],
int custom_lags, int width, int get_precision, int custom_size);
int custom_print_percent(va_list args_in_list, char buff[],
int custom_lags, int width, int get_precision, int custom_size);
int custom_print_int(va_list args_in_list, char buff[],
int custom_lags, int width, int get_precision, int custom_size);
int custom_print_binary(va_list args_in_list, char buff[],
int custom_lags, int width, int get_precision, int custom_size);
int custom_print_unsigned(va_list args_in_list, char buff[],
int custom_lags, int width, int get_precision, int custom_size);
int custom_print_octal(va_list args_in_list, char buff[],
int custom_lags, int width, int get_precision, int custom_size);
int custom_print_hexadecimal(va_list args_in_list, char buff[],
int custom_lags, int width, int get_precision, int custom_size);
int custom_print_hexa_upper(va_list args_in_list, char buff[],
int custom_lags, int width, int get_precision, int custom_size);
int custom_print_hexa(va_list args_in_list, char map_to[], char buff[],
int custom_lags, char lag_sh, int width, int get_precision, int custom_size);
int custom_print_non_printable(va_list args_in_list, char buff[],
int custom_lags, int width, int get_precision, int custom_size);
int custom_print_pointer(va_list args_in_list, char buff[],
int custom_lags, int width, int get_precision, int custom_size);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list args_in_list);
int get_precision(const char *format, int *i, va_list args_in_list);
int get_size(const char *format, int *i);
int print_reverse(va_list args_in_list, char buff[],
int custom_lags, int width, int get_precision, int custom_size);
int print_rot13string(va_list args_in_list, char buff[],
int custom_lags, int width, int get_precision, int custom_size);
int handle_write_char(char c, char buff[],
int custom_lags, int width, int get_precision, int custom_size);
int write_number(int is_positive, int index, char buff[],
int custom_lags, int width, int get_precision, int custom_size);
int write_num(int index, char buff[], int custom_lags, int width,
int get_precision, int length, char padd, char extra_c);
int write_pointer(char buff[], int index, int length,
int width, int custom_lags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_neg, int index,
char buff[], int custom_lags, int width,
int get_precision, int custom_size);
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif

