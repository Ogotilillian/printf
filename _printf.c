/**
 * _printf-the main function that emitates the standard output printf.
 * *format: Contains the character to be checked
 * ...: This is representing the variadic funtion
 * Return: always 0 (succes).
 */
int _printf(const char *format, ...)
{
	int joval_s = 0;
va_list args_in_list;
if (format == NULL)
	return (-1);
va_start(args_in_list, format);
while (*format)
{
if (*format != '%')
		write(1, format, 1);
joval_s++;
else
{
		format++;
	    if (*format == '\0')
break;
	    if (*format == '%')
write(1, format, 1);
joval_s++;
	else if (*format == 'c')
	{
		char c = va_arg(args_in_list, int);
write(1, &c, 1);
joval_s++;
}
else if (*format == 's')
{
	char *str = va_arg(args_in_list, char*);
int len_str = 0;
	    while (str[len_str] != '\0')
{
len_str++;
}
write(1, str, len_str);
joval_s += len_str;
}}
format++;
}
va_end(args_in_list);
return (joval_s);
}
