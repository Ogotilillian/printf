#include "main.h"

/**
 * _printf-the main function that emitates the standard
 * output printf.
 * format: Contains the character to be checked
 * ...: This is representing the variadic funtion
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

	/**
     * A loop that iterates through the characters of the list
	*/

	    if (*format != '%')

{

		/**
			 * format should not be the percentile
*/

		write(1, format, 1);
            
		/**
	     * the character is written to standard output
*/
joval_s++;

	}
else
{

		/**
	     * the character is percentile
*/

		format++;

	    /**
	 * skip the percentile and check the next character
*/

	    if (*format == '\0')
break;
if (*format == '%')

{

write(1, format, 1);
joval_s++;
}

/**
	 * handles the '%%' situation
*/

	else if (*format == 'c')
	
	{

		char c = va_arg(args_in_list, int);
write(1, &c, 1);
joval_s++;
}

/**
	 * handles the '%C' situation
*/

	else if (*format == 's')

{

		char *str = va_arg(args_in_list, char*);
int len_str = 0;

/**
* calculate the lenth of the string
*/
	    while (str[len_str] != '\0')
{
len_str++;
}
/**
 * write the string to the stduot
*/
write(1, str, len_str);
joval_s += len_str;
}
}
format++;
    }

va_end(args_in_list);
return (joval_s);
}
