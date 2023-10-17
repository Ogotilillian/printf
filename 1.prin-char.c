#include "main.h"

/**
 * prin_char - This is the functin that works to make sure a
 * char is printed.
 * @args_in_list: Arguments in a list.
 * @custom_lags: in charge of active flags.
 * @buff: connects with the print handler.
 * @width: handles the with.
 * @get_precision: handles the precision.
 * @custom_size: common on size.
 * Return: Number of chars prin.
 */
int prin_char(va_list args_in_list, char buff[], int custom_lags,
		int width, int get_precision, int custom_size)

{
	char c = va_arg(args_in_list, int);

	return (write_handle_char(c, buff, custom_lags, width,
			get_precision, custom_size));
}

/**
 *custom_print_percent - Prints a percent sign with repeat
 * @args_in_list: List of arguments
 * @buff: Buffer array to handle print
 * @custom_lags: Calculates active flags
 * @width: Get width.
 * @get_precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int custom_print_percent(va_list args_in_list, char buff[],
    int custom_lags, int width, int get_precision, 
    int custom_size)
{
  	UNUSED(buff);
	UNUSED(custom_lags);
	UNUSED(width);
	UNUSED(get_precision);
	UNUSED(custom_size);


    char percent = '%';

    if (custom_lags & F_ZERO) {
        // Handle zero padding
        for (int i = 0; i < width - 1; i++) {
            write(1, &percent, 1);
        }
    }

    // Write the '%' character itself
    write(1, &percent, 1);

    if (!(custom_lags & F_ZERO)) {
        // Handle other padding
        for (int i = 0; i < width - 1; i++) {
            write(1, " ", 1);
        }
    }

    return width > 1 ? width : 1;
}
