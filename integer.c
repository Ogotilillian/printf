#include "main.h"
/**
  *integer_specifier-hanlde iteger
  *@bingoo:list
  *Return:strlen.
  */
int integer_specifier(va_list bingoo)
{
	int num = va_arg(bingoo, int);
	char num_str[20];
	snprintf(num_str, sizeof(num_str), "%d", num);
	write(1, num_str, strlen(num_str));
	return (strlen(num_str));
}
