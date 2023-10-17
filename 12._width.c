/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int width = 0;

    while (is_digit(format[curr_i]))
    {
        width = width * 10 + format[curr_i] - '0';
        curr_i++;
    }

    if (format[curr_i] == '*')
    {
        curr_i++;
        width = va_arg(list, int);
    }

    *i = curr_i - 1;

    return width;
}

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Size specifier (S_LONG or S_SHORT) or 0 if not found.
 */
int get_size(const char *format, int *i)
{
    int curr_i = *i + 1;
    int size = 0;

    if (format[curr_i] == 'l')
    {
        size = S_LONG;
        curr_i++;
    }
    else if (format[curr_i] == 'h')
    {
        size = S_SHORT;
        curr_i++;
    }

    *i = curr_i - 1;
    return size;
}

/**
 * get_precision - Parses precision specifications in the format string
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;

    if (format[curr_i] != '.')
        return (precision);

    if (format[curr_i + 1] == '*') {
        // Precision is specified using '*'
        precision = va_arg(list, int);
        curr_i += 2;
    } else {
        // Precision is specified using digits
        precision = 0;
        while (is_digit(format[curr_i + 1])) {
            precision = precision * 10 + (format[curr_i + 1] - '0');
            curr_i++;
        }
        curr_i++;
    }

    *i = curr_i - 1;

    return (precision);
}

/**
 * get_flags - Parses the format string and extracts formatting flags.
 * @format: Formatted string with arguments.
 * @i: Index to keep track of the current position in the format string.
 * @list: List of arguments (not used in this example).
 * Return: Flags extracted from the format string.
 */
int get_flags(const char *format, int *i, va_list list)
{
    int curr_i;
    int flags = 0;

    for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
        if (format[curr_i] == '!') // Introducing a new flag '!'
        {
            flags |= F_EXCLAMATION;
        }
        else if (format[curr_i] == '$') // Introducing a new flag '$'
        {
            flags |= F_DOLLAR;
        }
        else if (format[curr_i] == '<') // Introducing a new flag '<'
        {
            flags |= F_LEFT_ARROW;
        }
        else if (format[curr_i] == '>') // Introducing a new flag '>'
        {
            flags |= F_RIGHT_ARROW;
        }
        else if (format[curr_i] == '?') // Introducing a new flag '?'
        {
            flags |= F_QUESTION;
        }
        else
        {
            break;
        }
    }

    *i = curr_i - 1;

    return flags;
}
