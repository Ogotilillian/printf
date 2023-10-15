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
	int buf, j = 0, k = 0;
	int joval_s = 0;
	va_list args_in_list;
	 char buff[BUFSIZ];
	if (format == NULL)
		return (-1);
	va_start(args_in_list, format);
	while (format && format[j] != '%')
	{
		j++;
		if (format != '%')
		{
			buff[buf++] = format[j];
			if (buf == BUFSIZ)
				prin_buff(buff, &buf);
			/*write(1, format, 1);*/
			joval_s++;
		}
		else
		{
		prin_buff(buff, &buf);
		lags = flags(format, &j);
		width = findwidth(format, &j, args_in_list);
			get_precision = precision(format, &j, args_in_list);
			size = get_size(format, &j);
			++j;
			k = handle_print(format, &j, list, buff, lags, width, get_precision, size);
			if (k == -1)
				return (-1);
			joval_s += k;
		}
	}
prin_buff(buff, &buf);
va_end(list);
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
