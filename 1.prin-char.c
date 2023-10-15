#include "main.h"

/**
 * prin_char - This is the functin that works to make sure a
 * char is printed.
 * @args_in_list: Arguments in a list.
 * @lags: in charge of active flags.
 * @buff: connects with the print handler.
 * @width: handles the with.
 * @get_precision: handles the precision.
 * @size: common on size.
 * Return: Number of chars prin.
 */
int prin_char(va_list args_in_list, char buff[], int lags,
		int width, int get_precision, int size)

{
	char c = va_arg(args_in_list, int);

	return (write_handle_char(c, buff, lags, width,
			get_precision, size));
}
