#include "main.h"
#include <stdarg.h>
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @lst: List of arguments to be printed.
 * @i: an ind
 * @buff: Buffer array to handle print.
 * @flag: Calculates active flags
 * @width: get width
 * @size: Size specifier
 * @precision: Precision specification
 *
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *i, va_list lst,
		char buff[], int flag, int width, int size, int precision)
{
	int p, chars = -1, len = 0;

	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (p = 0; fmt_types[p].fmt != '\0'; p++)
	{
		if (fmt[*i] == fmt_types[i].fmt)
			return (fmt_types[p].fn(buff, lst, flag, width, size, precision));
	}
	if (fmt_types[p].fmt == '\0')
	{
		if (fmt[*i] == '\0')
			return (-1);
		len = len + write(1, "%%", 1);
		if (fmt[*i - 1] == ' ')
			len = len + write(1, " ", 1);
		else if (width)
		{
			--(*i);
			while (fmt[*i] != ' ' && fmt[*i] != '%')
				--(*i);
			if (fmt[*i] == ' ')
				--(*i);
			return (1);
		}
		len = len + write(1, &fmt[*i], 1);
		return (len);
	}
	return (chars);
}
