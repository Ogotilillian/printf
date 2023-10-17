#include "main.h"
/**
 * _printf-the main function that emitates the standard output printf.
 * @format: It is a string containing format specifiers
 * and optional text, format specifiers start with a % character and are used
 * to specify how the additional arguments (variadic arguments) should be
 * formatted and inserted into the string.
 * ...: This is representing the variadic funtion
 * Return: always 0 (succes).
 */
int _printf(const char *format, ...)
{
	int buf, j = 0, k = 0, get_precision, custom_size;
	int joval_s = 0, custom_lags, width;
	va_list args_in_list;
	 char buff[BUF_SIZ];

	if (format == NULL)
		return (-1);
	va_start(args_in_list, format);
	while (format && format[j] != '%')
	{
		j++;
		if (format != '%')
		{
			buff[buf++] = format[j];
			if (buf == BUF_SIZ)
				prin_buff(buff, &buf);
			/*write(1, format, 1);*/
			joval_s++;
		}
		else
		{
		prin_buff(buff, &buf);
		custom_lags = custom_lags(format, &j);
		width = _width(format, &j, args_in_list);
			get_precision = precision(format, &j, args_in_list);
			custom_size = custom_size(format, &j);
			++j;
			k = handle_print(format, &j, args_in_list, buff, custom_lags, width, custom_precision, custom_size);
			if (k == -1)
				return (-1);
			joval_s += k;
		}
	}
prin_buff(buff, &buf);
va_end(args_in_list);
return (joval_s);
}
/**
 * prin_buff-This is the function that handles BUFSIZ.
 * @buff: Array of chars
 * @buf: index at which we add the following character and also
 * also represents the length.
 * Return: void.
 */
void prin_buff(char buff, int *buf)
{
	if (*buf > 0)
		write(1, &buff[0], *buf);
	*buf = 0;
}
