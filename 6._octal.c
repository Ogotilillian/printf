/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int unsigned_octal(va_list args_in_list, char buff[], int custom_lags, int width, int get_precision, int custom_size)
{
    int i = BUF_SIZ - 2;
    unsigned long int num = va_arg(args_in_list, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width); // Unused parameter, remove if needed for width handling

    num = convert_size_unsgnd(num, size);

    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    // Use a for loop to convert the number to octal in reverse
    for (i = i - 1; init_num != 0; i--)
    {
        buffer[i] = (init_num % 8) + '0';
        init_num /= 8;
    }

    // Replace the if statement with a while loop
    while ((flags & F_HASH) && (i >= 0) && (buffer[i] == '0'))
    {
        i--;
    }

    i++;

    return write_unsgnd(0, i, buffer, flags, width, precision, size);
}
