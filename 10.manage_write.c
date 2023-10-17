#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Prints a character
 * @c: The character to be printed
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags.
 * @width: Get width.
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed.
 */
int handle_write_char(char c, char buff[],
    int custom_lags, int width, int get_precision, int custom_size)
{
    int i = 0;
    char padd = ' ';

    if (custom_lags & F_ZERO)
        padd = '0';

    buff[i++] = c;
    buff[i] = '\0';

    if (width > 1)
    {
        buff[BUF_SIZ - 1] = '\0';
        for (i = 0; i < width - 1; i++)
            buffer[BUF_SIZ - i - 2] = padd;

        if (custom_lags & F_MINUS)
            return (write(1, &buff[0], 1) +
                    write(1, &buff[BUF_SIZ - i - 1], width - 1));
        else
            return (write(1, &buff[BUF_SIZ - i - 1], width - 1) +
                    write(1, &buff[0], 1));
    }

    return (write(1, &buff[0], 1));
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
int write_number(int is_neg, int index, char buff[],
    int flags, int width, int precision, int size)
{
    int length = BUFF_SIZE - ind - 1;
    char padd = ' ', extra_ch = 0;

    if ((flags & F_ZERO) && !(flags & F_MINUS))
        padd = '0';

    if (is_negative)
        extra_ch = '-';
    else if (flags & F_PLUS)
        extra_ch = '+';
    else if (flags & F_SPACE)
        extra_ch = ' ';

    return (write_num(ind, buffer, flags, width, precision,
        length, padd, extra_ch));
}

/**
 * write_num - Writes a number using a buffer
 * @ind: Index at which the number starts in the buffer
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specifier
 * @length: Number length
 * @padd: Padding character
 * @extra_c: Extra character
 *
 * Return: Number of characters printed.
 */
int write_num(int ind, char buffer[], int flags, int width, int precision, int length, char padd, char extra_c)
{
    int i, padd_start = 1;

    if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
        return (0);

    if (precision > 0 && precision < length)
        padd = ' ';

    while (precision > length)
    {
        buffer[--ind] = '0';
        length++;
    }

    if (width > length)
    {
        for (i = 1; i < width - length + 1; i++)
            buffer[i] = padd;

        buffer[i] = '\0';

        if (flags & F_MINUS)
        {
            return (write(1, &buffer[ind], length) + write(1, &buffer[1], i));
        }
        else
        {
            return (write(1, &buffer[1], i) + write(1, &buffer[ind], length));
        }
    }

    if (extra_c)
        buffer[--ind] = extra_c;

    return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: 1 if the number is negative, 0 if not
 * @ind: Index at which the number starts in the buffer
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed.
 */
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size)
{
    int length = BUFF_SIZE - ind - 1, i = 0;
    char padd = ' ';

    if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
        return (0);

    if (precision > 0 && precision < length)
        padd = ' ';

    if ((flags & F_ZERO) && !(flags & F_MINUS))
        padd = '0';

    if (width > length)
    {
        for (i = 0; i < width - length; i++)
            buffer[i] = padd;

        buffer[i] = '\0';

        if (flags & F_MINUS)
        {
            return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
        }
        else
        {
            return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
        }
    }

    if (is_negative)
        buffer[--ind] = '-';

    return (write(1, &buffer[ind], length));
