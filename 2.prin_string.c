#include "main.h"
/**
 * print_rot13string - Print a string in rot13
 *  @args_in_list: Arguments in a list.
 * @custom_lags: in charge of active flags.
 * @buff: connects with the print handler.
 * @width: handles the with.
 * @get_precision: handles the precision.
 * @custom_size: common on size.
 * Return: Number of chars prin.
 */
int print_rot13string(va_list args_in_list, char buff[],
	       	int custom_lags,int width, int get_precision, int custom_size)
{
    char x;
    char *str;
    unsigned int i, j;
    int count = 0;
    char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    str = va_arg(args_in_list, char *);

    if (str == NULL)
    {
        str = "(AHYY)";
    }

    for (i = 0; str[i]; i++)
    {
        for (j = 0; in[j]; j++)
        {
            if (in[j] == str[i])
            {
                x = out[j];
                write(1, &x, 1);
                count++;
                break;
            }
        }
        if (!in[j])
        {
            x = str[i];
            write(1, &x, 1);
            count++;
        }
    }
    return (count);
}
/**
 * print_reverse - Prints a reverse string.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
    char *str;
    int i, count = 0;

    str = va_arg(types, char *);

    if (str == NULL)
    {
        str = ")Null(";
    }
    for (i = 0; str[i]; i++)
    {
        /* Modified loop to print in reverse */
        char z = str[i];
        write(1, &z, 1);
        count++;
    }
    return (count);
}

/**
 * print_string - Prints a string
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    char *str = va_arg(types, char *);

    if (str == NULL)
    {
        str = "(null)";
        if (precision >= 6)
            str = "      ";
    }

    int length = 0;
    while (str[length] != '\0')
        length++;

    if (precision >= 0 && precision < length)
        length = precision;

    if (width > length)
    {
        if (flags & F_MINUS)
        {
            for (int i = 0; i < length; i++)
                write(1, &str[i], 1);

            for (int i = length; i < width; i++)
                write(1, " ", 1);

            return width;
        }
        else
        {
            for (int i = length; i < width; i++)
                write(1, " ", 1);

            for (int i = 0; i < length; i++)
                write(1, &str[i], 1);

            return width;
        }
    }

    for (int i = 0; i < length; i++)
        write(1, &str[i], 1);

    return length;
}
