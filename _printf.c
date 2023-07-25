#include "main.h"

void print_buffer_of_string(char buffer[], int *buff_nd);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed characters.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, the_precision, the_size, the_flags, the_width, printed_characters = 0, buff_nd = 0;
	va_list list;
	char buffer_ch[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer_ch[buff_nd++] = format[i];
			if (buff_nd == BUFF_SIZE)
			{
				print_buffer_of_string(buffer_ch, &buff_nd);
			}

			printed_characters++;
		}
		else
		{
			print_buffer_of_string(buffer_ch, &buff_nd);
			the_flags = get_flags(format, &i);
			the_width = get_width(format, &i, list);
			the_precision = get_precision(format, &i, list);
			the_size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer_ch, the_flags, the_width, the_precision, the_size);
			if (printed == -1)
			{
				return (-1);
			}
			printed_characters += printed;
		}
	}

	print_buffer_of_string(buffer_ch, &buff_nd);

	va_end(list);

	return (printed_characters);
}

/**
 * print_buffer_of_string - print give result if exist any character
 * @buffer: Array of characters
 * @buff_nd: the index that show all characters.
 */
void print_buffer_of_string(char buffer[], int *buff_nd)
{
	if (*buff_nd > 0)
	{
		write(1, &buffer[0], *buff_nd);
	}
	*buff_nd = 0;
}
