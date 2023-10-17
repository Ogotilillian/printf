#include "main.h"

/**
 * custom_manage_print - Prints an argument based on its type
 * and application
 * @formatt: Formatted string in which to print the arguments.
 * @index: index.
 *@args_in_list:Arguments in a list to be printed.
 * @buff: Buffer array to handle printf.
 * @custom_lags: Calculates active flags
 * @width: get width to be used.
 *@get_precision: Precision specification finder
 * @custom_size: Size specifierizer.
 * Return: 1 or 2;
 */
int custom_manage_print(const char *formatt, int *index, va_list args_in_list,
		 char buff[],int custom_lags, int width,
		  int get_precision, int custom_size)
{
	int unnwom_len = 0;
	int printed_chars = -1;
	formatt_t fmt_types[] = {{'c', custom_print_char}, {'s', custom_print_string},
		{'%', custom_print_percent}, {'i', custom_print_int}, {'d', custom_print_int},
		{'b', custom_print_binary}, {'u', custom_print_unsigned},
	    {'o', custom_print_octal}, {'x', custom_print_hexadecimal},
	    {'X',custom_ print_hexa_upper}, {'p', custom_print_pointer},
	    {'S', custom_print_non_printable}, {'r', custom_print_reverse},
	    {'R', custom_print_rot13string}, {'\0', NULL}    };
int i = 0;

while (fmt_types[i].formatt != '\0') {
        if (fmt[*index] == fmt_types[i].formatt) {
		return fmt_types[i].fn(args_in_list, buff, custom_lags, width, get_precision,
			       	cutsom_size);}
	i++;
    }
    
    if (fmt_types[i].formatt == '\0')
    {
      if (formatt[*index] == '\0')
      {
	      return (-1);
      }
      unnwom_len += write(1, "%%", 1);
      if (formatt[*index - 1] == ' ')
      {
	      unnwom_len += write(1, " ", 1);
      }
      else if (width)
      {
	      --(*index);
            while (formatt[*index] != ' ' && formatt[*index] != '%') {
		    --(*index);
	    }
	    if (formatt[*index] == ' ')
	    {
                --(*index);
	    }
	    return 1;
      }
      unnwom_len += write(1, &formatt[*index], 1);
      return unnwom_len;
    }
    return printed_chars;
}
