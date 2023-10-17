#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * custom_rint_pointer - Prints the value of a pointer variable
 * @args_in_list: List of arguments
 * @buff: Buffer array to handle print
 * @custom_lags: Calculates active flags
 * @width: Get width
 * @get_precision: Precision specification
 * @custom_size: Size specifier
 * Return: Number of chars printed.
 */
int custom_print_pointer(va_list args_in_list, char buff[],
	int custom_lags, int width, int get_precision, int custom_size)
{
    char extra_c = 0, padd = ' ';
    int ind = BUF_SIZ - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
    unsigned long num_addrs;
    char map_to[] = "0123456789abcdef";
    void *addrs = va_arg(args_in_list, void *);

    if (addrs == NULL)
        return (write(1, "(nil)", 5));

    buffer[BUF_SIZ - 1] = '\0';

    num_addrs = (unsigned long)addrs;

    while (num_addrs > 0)
    {
        buff[index--] = map_to[num_addrs % 16];
        num_addrs /= 16;
        length++;
    }

    if ((custom_lags & F_ZERO) && !(custom_lags & F_MINUS))
        padd = '0';

    if (custom_lags & F_PLUS)
        extra_c = '+', length++;
    else if (custom_lags & F_SPACE)
        extra_c = ' ', length++;

    index++;

return write_pointer(buff, index, length, width, custom_lags,
	       	padd, extra_c, padd_start);
}

/**
 *
 * custom_print_non_printable - Prints ascii codes in hexa of 
 * non-printable chars
 * @args_in_list: List of arguments
 * @buff: Buffer array tomanage print
 * @custom_lags: Calculates active flags
 * @width: Get width
 * @get_precision: Precision specification
 * @custom_size: Size specifier
 * Return: Number of chars printed
 */
int custom_print_non_printable(va_list args_in_list, char buff[],
	int custom_lags, int width, int get_precision, int custom_size)
{
    int i = 0, offset = 0;
    char *str = va_arg(args_in_list, char *);

    if (str == NULL)
        return (write(1, "(null)", 6);

    while (str[i] != '\0')
    {
        if (is_printable(str[i]))
            buff[i + offset] = str[i];
        else
            offset += append_hexa_code(str[i], buffer, i + offset);

        i++;
    }

    buff[i + offset] = '\0';
    return (write(1, buff, i + offset));
}
