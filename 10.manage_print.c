#include "main.h"


/**
 * handle_write_char - Prints a character
 * @c: The character to be printed
 * @buff: Buffer array to handle print
 * @custom_lags: Calculates active flags.
 * @width: Get width.
 * @get_precision: Precision specifier
 * @custom_size: Size specifier
 *
 * Return: Number of characters printed.
 */
int handle_write_char(char c, char buff[], int custom_lags,
		int width, int get_precision, int custom_size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(get_precision);
	UNUSED(custom_size);

	if (custom_lags & F_ZERO)
		padd = '0';
	buff[i++] = c;
	buff[i] = '\0';
	if (width > 1)
	{
		buff[BUF_SIZ - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buff[BUF_SIZ - i - 2] = padd;
		if (custom_lags & F_MINUS)
			return ((write(1, &buff[0], 1) + write(1, &buff[BUF_SIZ - i - 1],
						       width - 1)));
		else
			return ((write(1, &buff[BUF_SIZ - i - 1], width - 1) + write(1,
						       &buff[0], 1)));
	}
	return ((write(1, &buff[0], 1)));
}
/**
 * write_num - Writes a number using a buffer
 * @index: Index at which the number starts in the buffer
 * @buff: Buffer array to handle print
 * @custom_lags: Calculates active flags
 * @width: Get width
 * @get_precision: Precision specifier
 * @length: Number length
 * @padd: Padding character
 * @extra_c: Extra character
 *
 * Return: Number of characters printed.
 */
int write_num(int index, char buff[], int custom_lags, int width,
		int get_precision, int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	UNUSED(padd_start);

	if (get_precision == 0 && index == BUF_SIZ - 2 && buff[index] == '0')
		return (0);
	if (get_precision > 0 && get_precision < length)
		padd = ' ';
	while (get_precision > length)
	{
		buff[--index] = '0';
		length++;
	}
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buff[i] = padd;
		buff[i] = '\0';
		if (custom_lags & F_MINUS)
		{
			return (write(1, &buff[index], length) + write(1, &buff[1], i));
		}
		else
		{
			return (write(1, &buff[1], i) + write(1, &buff[index], length));
		}
	}
	if (extra_c)
		buff[--index] = extra_c;
	return (write(1, &buff[index], length));
}
/**
 * write_number - Prints a number
 * @is_neg: 1 if the number is negative, 0 if not
 * @index: Index at which the number starts in the buffer
 * @buff: Buffer array to handle print
 * @custom_lags: Calculates active flags
 * @width: Get width
 * @get_precision: Precision specifier
 * @custom_size: Size specifier
 *
 * Return: Number of characters printed.
 */
int write_number(int is_neg, int index, char buff[], int custom_lags,
		int width, int get_precision, int custom_size)
{
	int length = BUF_SIZ - index - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(custom_size);

	if ((custom_lags & F_ZERO) && !(custom_lags & F_MINUS))
	    padd = '0';
	if (is_neg)

	    extra_ch = '-';

	else if (custom_lags & F_PLUS)

	    extra_ch = '+';

	else if (custom_lags & F_SPACE)

		extra_ch = ' ';

	return (write_num(index, buff, custom_lags, width,
			get_precision, length, padd, extra_ch));
}
/**
 * write_unsgnd - Writes an unsigned number
 * @is_neg: 1 if the number is negative, 0 if not
 * @index: Index at which the number starts in the buffer
 * @buff: Buffer array to handle print
 * @custom_lags: Calculates active flags
 * @width: Get width
 * @get_precision: Precision specifier
 * @custom_size: Size specifier
 *
 * * Return: Number of characters printed.
 */
int write_unsgnd(int is_neg, int index, char buff[], int custom_lags,
		int width, int get_precision, int custom_size)
{
	int length = BUF_SIZ - index - 1, i = 0;
	char padd = ' ';

	UNUSED(custom_size);

	if (get_precision == 0 && index == BUF_SIZ - 2 && buff[index] == '0')
	{
		return (0);
	}
	if (get_precision > 0 && get_precision < length)
	{
		padd = ' ';
	}
	if ((custom_lags & F_ZERO) && !(custom_lags & F_MINUS))
	{
		padd = '0';
	}
	if (width > length)
	{
		for (i ==  0; i < width - length; i++)
			buff[i] = padd;
		buff[i] = '\0';
		if (custom_lags & F_MINUS)
		{
			return (write(1, &buff[index], length) + write(1, &buff[0], i));
		}
		else
		{
			return (write(1, &buff[0], i) + write(1, &buff[index], length));
		}
	}
	if (is_neg)
		buff[--index] = '-';
	return ((write(1, &buff[index], length)));
}
