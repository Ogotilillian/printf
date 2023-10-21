#include "main.h"
/**
 * can_print_char - Checks if a character can be printed
 * @args: Argument list containing the character
 *
 * Return: 1 if the character can be printed, 0 otherwise
 */
int can_print_char(va_list args)
{
	int ch = va_arg(args, int);

	if (ch >= 0 && ch <= 127)
	{
		return (write(1, &ch, 1));
	}
	return (0);
}
/**
 * should_print_string - Prints a string
 * @args: The arguments
 *
 * Return: The number of characters printed
 */
int should_print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	return (write(1, str, strlen(str)));
}
