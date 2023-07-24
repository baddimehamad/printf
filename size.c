#include "main.h"
/**
 * get_size - calculates the size
 * @format: Formatted string
 * @pi:list of arguments to be printed
 *
 * Return: size
 */
int get_size(const char *format, int *pi)
{
	int p, size;

	p = *pi + 1;
	size = 0;
	if (format[p] == 'l')
		size = S_LONG;
	else if (format[p] == 'h')
		size = S_SHORT;
	if (size == 0)
		*pi = p - 1;
	else
		*pi = p;
	return (size);
}
