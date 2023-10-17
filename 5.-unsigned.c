int _unsigned(va_list args_in_list, char buff[],
    int custom_lags, int width, int get_precision, int custom_size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);

    num = convert_size_unsgnd(num, size);

    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    do {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    i++;

    return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
