#include "main.h"
/**
 * print_pointer - this function Prints a value of the pointer variable
 * @precision: specify the Precision
 * @types: the arguments
 * @flags:  calc the flags
 * @buffer: the buffer that handel print
 * @width: the Width
 * @size: the Size
 * Return: value
 */
int print_pointer(va_list types, int the_width, char buffer_chars[], int the_flags, int the_size, int the_precision)
{
	char ex_c = 0, p_add = ' ';
	int ind = BUFF_SIZE - 2, length = 2, p_add_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(the_width);
	UNUSED(the_size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer_chars[BUFF_SIZE - 1] = '\0';
	UNUSED(the_precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer_chars[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((the_flags & F_ZERO) && !(the_flags & F_MINUS))
		p_add = '0';
	if (the_flags & F_PLUS)
		ex_c = '+', length++;
	else if (the_flags & F_SPACE)
		ex_c = ' ', length++;

	ind++;

	return (write_pointer(buffer_chars, ind, length,the_width, the_flags, p_add, ex_c, p_add_start));
}
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @precision: specify the Precision
 * @types: the arguments
 * @flags:  calc the flags
 * @buffer: the buffer that handel print
 * @width: the Width
 * @size: the Size
 * Return: value
 */
int print_non_printable(va_list types, int the_width, char buffer_chars[], int the_flags, int the_size, int the_precision)
{
	int i = 0, offset_v = 0;
	char *str = va_arg(types, char *);

	UNUSED(the_flags);
	UNUSED(the_width);
	UNUSED(the_precision);
	UNUSED(the_size);

	if (str == NULL){
		return (write(1, "(null)", 6));
	}

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer_chars[i + offset_v] = str[i];
		else
			offset_v += append_hexa_code(str[i], buffer_chars, i + offset_v);

		i++;
	}

	buffer_chars[i + offset_v] = '\0';

	return (write(1, buffer_chars, i + offset_v));
}
/**
 * print_pointer - this function Prints a value of the pointer variable
 * @precision: specify the Precision
 * @types: the arguments
 * @flags:  calc the flags
 * @buffer: the buffer that handel print
 * @width: the Width
 * @size: the Size
 * Return: value
 */
int print_pointer(va_list types, int the_width, char buffer_chars[], int the_flags, int the_size, int the_precision)
{
	char ex_c = 0, p_add = ' ';
	int ind = BUFF_SIZE - 2, length = 2, p_add_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(the_width);
	UNUSED(the_size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer_chars[BUFF_SIZE - 1] = '\0';
	UNUSED(the_precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer_chars[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((the_flags & F_ZERO) && !(the_flags & F_MINUS))
		p_add = '0';
	if (the_flags & F_PLUS)
		ex_c = '+', length++;
	else if (the_flags & F_SPACE)
		ex_c = ' ', length++;

	ind++;

	return (write_pointer(buffer_chars, ind, length,the_width, the_flags, p_add, ex_c, p_add_start));
}
/**
 * print_rot13string - Print a string in rot13.
 * @precision: specify the Precision
 * @types: the arguments
 * @flags:  calc the flags
 * @buffer: the buffer that handel print
 * @width: the Width
 * @size: the Size
 * Return: value
 */
int print_rot13string(va_list types, int the_width, char buffer_chars[], int the_flags, int the_size, int the_precision)
{
	char x;
	char *str_v;
	unsigned int i, j;
	int count = 0;
	char array_in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char array_out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str_v = va_arg(types, char *);
	UNUSED(buffer_chars);
	UNUSED(the_flags);
	UNUSED(the_width);
	UNUSED(the_precision);
	UNUSED(the_size);

	if (str_v == NULL){
		str_v = "(AHYY)";
	}
	for (i = 0; str_v[i]; i++)
	{
		for (j = 0; array_in[j]; j++)
		{
			if (array_in[j] == str_v[i])
			{
				x = array_out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!array_in[j])
		{
			x = str_v[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
/**
 * print_reverse - Prints reverse string.
 * @precision: specify the Precision
 * @types: the arguments
 * @flags:  calc the flags
 * @buffer: the buffer that handel print
 * @width: the Width
 * @size: the Size
 * Return: value
 */

int print_reverse(va_list types, int the_width, char buffer_chars[], int the_flags, int the_size, int the_precision)
{
	char *str_v;
	int i, count = 0;

	UNUSED(buffer_chars);
	UNUSED(the_flags);
	UNUSED(the_width);
	UNUSED(the_size);

	str_v = va_arg(types, char *);

	if (str_v == NULL)
	{
		UNUSED(the_precision);

		str_v = ")Null(";
	}
	for (i = 0; str_v[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str_v[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

