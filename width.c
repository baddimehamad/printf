#include "main.h"
/**
 * get_width - calculates the width
 * @format: string to print an argument
 * @pi: list of arguments to prints
 * @lst: list of all arguments
 *
 * Return: width
 */
int get_width(const char *format, int *pi, va_list lst)
{
	int width = 0, p;

	for (p = *pi + 1; format[p] != '\0'; p++)
	{
		if (is_digit(format[p]))
		{
			width = width * 10;
			width += format[p] - '0';
		}
		else if (format[p] == '*')
		{
			p++;
			width += va_arg(lst, int);
			break;
		}
		else
			break;
	}
	*pi = p - 1;
	return (width);
}
