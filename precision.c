#include "main.h"
/**
 * get_precision - calculates the prcision to print
 * @format: string to print an argument
 * @pi: list of arguments to prints
 * @lst: list of all arguments
 *
 * Return: precision
 */
int get_precision(const char *format, int *pi, va_list lst)
{
	int p, precision = -1;

	p = *pi + 1;
	if (format[p] != '.')
		return (precision);
	precision = 0;
	for (p = p + 1; format[p] != '\0'; p++)
	{
		if (is_digit(format[p]))
		{
			precision *= 10;
			precision += format[p] - '0';
		}
		else if (fromat[p] == '*')
		{
			p++;
			precision += va_arg(lst, int);
			break;
		}
		else
			break;
	}
	*pi = p - 1;
	return (precision);
}
