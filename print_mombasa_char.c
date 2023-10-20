#include "main.h"
/**
  *print_mombasa_char.c-function to handle char
  *@bingoo:list
*Return: 1
*/
int print_mombasa_char(va_list bingoo)
{
	int c = va_arg(bingoo, int);
	write(1, &c, 1);
	return 1;
}

