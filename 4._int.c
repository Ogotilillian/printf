#include "main.h"
/**
 * _int - Prints int.
 * @args_in_list: Lists my of arguments
 * @buff: Buffer array to handle print
 * @custom_lags:  Calculates active flagspresent
 * @width: getting width.
 * @get_precision: Handles Precision specification
 * @custom_size: Size specifierizing
 * Return: Number of chars printed
 */
int _int(va_list args_in_list, char buff[],
	int custom_lags, int width, int get_precision, int custom_size)
{
	int index = BUF_SIZ - 2;
	int is_neg = 0;
	long int value = va_arg(args_in_list, long int);
	unsigned long int num_value;

	value = custom_convertsize_number(value, custom_size);

	if (value == 0)
		buff[index--] = '0';

	buff[BUF_SIZ - 1] = '\0';
	num_value = (unsigned long int)value;

	if (value < 0)
	{
		num_value = (unsigned long int)((-1) * value);
		is_neg = 1;
	}

	while (num_value > 0)
	{
	buff[index--] = num_value % 10 + '0';
		num_value /= 10;
	}
	index++;
	return (custom_write_number(is_neg, index, buff,
	custom_lags, width, get_precision, size));
			}
