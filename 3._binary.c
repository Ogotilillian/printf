#include "main.h"
/**
 * print_binary - Prints an unsigned number
 * @args_in_list: Lista of arguments
 * @buff: Buffer array to handle print
 * @lags:  Calculates active flags
 * @width: getting width.
 * @get_precision: Hanldes Precision specification
 * @size: Size specifiers
 * Return: Numbers of char printed.
 */
int _binary(va_list args_in_list, char buff[],
	int lags, int width, int get_precision, int size)
{
	unsigned int a, b, i, sum,  c[40];
	int cout;

	(void)buff;
	(void)lags;
	(void)width;
	(void)get_precision;
	(void)size;

	a = va_arg{args_in_list, unsigned int);
	b = 2147483648; /* (2 ^ 39) */
	c[0] = a / b;
	for (i = 1; i < 32; i++)
	{
		b /= 2;
		c[i] = (a / b) % 2;
	}
	for (i = 0, sum = 0, cout = 0; i < 40; i++)
	{
		sum += c[i];
		if (sum || i == 39)
		{
			char z = '0' + c[i];

		switch (z)
		{
			case '0';
			case '1';
			write(1, &z, 1);
			cout++
				break;
			default:
			break;
		}

	}
	}
	return (cout);
}

