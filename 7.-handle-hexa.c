#include "main.h"
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width); // Unused parameter, remove if needed for width handling

    num = convert_size_unsgnd(num, size);

    // Ensure a non-empty buffer
    if (num == 0)
        buffer[i--] = '0';
    else {
        buffer[BUFF_SIZE - 1] = '\0';

        // Use a for loop to convert the number to hexadecimal in reverse
        for (i = i - 1; init_num != 0; i--) {
            buffer[i] = "0123456789abcdef"[init_num % 16];
            init_num /= 16;
        }
    }

    // Replace the condition for the F_HASH flag
    if (flags & F_HASH && num != 0) {
        buffer[i--] = 'x';
        buffer[i--] = '0';
    }

    i++;

    return write_unsgnd(0, i, buffer, flags, width, precision, size);
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width); // Unused parameter, remove if needed for width handling

    num = convert_size_unsgnd(num, size);

    // Ensure a non-empty buffer
    if (num == 0)
        buffer[i--] = '0';
    else {
        buffer[BUFF_SIZE - 1] = '\0';

        // Use a while loop to convert the number to uppercase hexadecimal in reverse
        while (init_num != 0) {
            buffer[i--] = "0123456789ABCDEF"[init_num % 16];
            init_num /= 16;
        }
    }

    // Modify the condition for the F_HASH flag
    if (flags & F_HASH && num != 0) {
        buffer[i--] = 'X';
        buffer[i--] = '0';
    }

    i++;

    return write_unsgnd(0, i, buffer, flags, width, precision, size);
}
/**
 * print_hexa - Prints a hexadecimal number in lower or upper case
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @flag_ch: Character to print with the F_HASH flag
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width); // Unused parameter, remove if needed for width handling

    num = convert_size_unsgnd(num, size);

    // Ensure a non-empty buffer
    if (num == 0)
        buffer[i--] = '0';
    else {
        buffer[BUFF_SIZE - 1] = '\0';

        // Use a while loop to convert the number to hexadecimal in reverse
        while (num > 0) {
            buffer[i--] = map_to[num % 16];
            num /= 16;
        }
    }

    // Modify the condition for the F_HASH flag
    if (flags & F_HASH && init_num != 0) {
        buffer[i--] = flag_ch;
        buffer[i--] = '0';
    }

    i++;

    return write_unsgnd(0, i, buffer, flags, width, precision, size);
}
