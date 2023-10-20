#include "main.h"
/**
  *print_dodoma_percent-the main code
  *@bingoo:list
  *Return: always 0.
  */
int print_dodoma_percent(va_list bingoo)
{
	char percent = '%';
	(void)bingoo;

	write(1, &percent, 1);
	return 1;
}
