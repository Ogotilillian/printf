#include "main.h"
/**
  *print_nairobi_string-function for strng
  *@bingoo:list
  *Return:len
  */
int print_nairobi_string(va_list bingoo)
{
	char *city = va_arg(bingoo, char *);
	int len = strlen(city);
	write(1, "City: ", 6);
	write(1, city, len);
	return len;
}
