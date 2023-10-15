#include "main.h"

/**
 * _string-Prints a string.
 * @args_in_list: Arguments in a list.
 * @buff: Buffer array to be printed
 * @lags: in charge of active flags.
 * @width: gets the width.
 * @get_precision: i handle precision.
 * @size: i am alright with size
 * Return: Number of chars printed
 */
int _string(va_list args_in_list, char buff[],
		int lags, int width, int get_precision, int size)
{
int length = 0, i;
	char *str = va_arg(args_in_list, char*);

	(void)buff;
		(void)width;
		(void)lags;
		(void)get_precision;
		(void)size;

		if (str == NULL)
		{
			str = "(null)";
			if (get_precision >= 6)
				str = "      ";
		}
}
for (j = 0; str[j] != '\0'; j++)
{
	length++;
}
if (get_precision >= 0 && get_precision < length)
{
	length = get_precision;
}
if (width > length)
{
	if (lags & F_MINUS)
	{
		write(1, &str[0], length);
		for (j = width - length; j > 0; j--)
		{
			write(1, " ", 1);
		}
		return (width);
	}
	else
	{
		for (j = width - length; j > 0; j--)
		{
			write(1, " ", 1);
		}
		write(1, &str[0], length);
		return (width);
	}
}
return (write(1, str, length));
}
