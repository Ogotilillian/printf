#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: The format string
 * @...: The optional arguments to be formatted
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			if (write(1, format, 1) == -1)
				return (-1);
			count++;
		}
		else
		{
			format++;
			if (*format == 'c')
				count += can_print_char(args);
			else if (*format == 's')
				count += should_print_string(args);
			else if (*format == '%')
			{
				if (write(1, "%", 1) == -1)
					return (-1);
				count++;
			}
		}
		format++;
	}

	va_end(args);

	return (count);
}
