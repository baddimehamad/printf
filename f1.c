#include "main.h"

/**
 * print_percent - prints the percent sign (%)
 * @the_precision: specify the precision
 * @types: the arguments
 * @the_flags: thie flags
 * @buffer_chars: the buffer that handle print
 * @the_width: the width
 * @the_size: the size
 *
 * Return: Number of chars printed
 */

int print_percent(va_list types, char buffer_chars[], int the_flags,
		int the_width, int the_size, int the_precision)
{
	UNUSED(the_width);
	UNUSED(buffer_chars);
	UNUSED(the_flags);
	UNUSED(the_size);
	UNUSED(the_precision);
	UNUSED(types);
	return (write(1, "%%", 1));
}
/**
 * print_string - prints a string
 * @the_precision: precision
 * @types: the arguments
 * @the_flags:  calc the flags
 * @buffer_chars: the buffer that handel print
 * @the_width: the Width
 * @the_size: the Size
 *
 * Return: characters printed
 */
int print_string(va_list types, char buffer_chars[], int the_flags,
		int the_width, int the_size, int the_precision)
{
	int length = 0, i;
	char *the_string = va_arg(types, char *);

	UNUSED(the_width);
	UNUSED(buffer_chars);
	UNUSED(the_flags);
	UNUSED(the_size);
	UNUSED(the_precision);
	if (the_string == NULL)
	{
		the_string = "(null)";
		if (the_precision >= 6)
			the_string = "      ";
	}
	while (the_string[length] != '\0')
		length++;
	if (the_precision >= 0 && the_precision < length)
	{
		length = the_precision;
	}
	if (the_width > length)
	{
		if (the_flags & F_MINUS)
		{
			write(1, &the_string[0], length);
			for (i = the_width - length; i > 0; i--)
				write(1, " ", 1);
			return (the_width);
		}
		else
		{
			for (i = the_width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &the_string[0], length);
			return (the_width);
		}
	}
	return (write(1, the_string, length));
}
/**
 * print_char - prints a character
 * @the_precision: specify the Precision
 * @types: the arguments
 * @the_flags:  calc the flags
 * @buffer_chars: the buffer that handel print
 * @the_width: the Width
 * @the_size: the Size
 *
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer_chars[], int the_flags,
		int the_width, int the_size, int the_precision)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer_chars, the_flags,
				the_width, the_precision, the_size));
}

/**
 * print_int - print an integer
 * @the_precision: specify the Precision
 * @types: the arguments
 * @the_flags:  calc the flags
 * @buffer_chars: the buffer that handel print
 * @the_width: the Width
 * @the_size: the Size
 *
 * Return: number of the printed caracters
 */
int print_int(va_list types, char buffer_chars[], int the_flags,
		int the_width, int the_size, int the_precision)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, the_size);
	if (n == 0)
		buffer_chars[i--] = '0';

	buffer_chars[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer_chars[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(is_negative, i, buffer_chars,
				the_flags, the_width, the_precision, the_size));
}
/**
 * print_binary - prints the unsigned numbers
 * @the_precision: specify the Precision
 * @types: the arguments
 * @the_flags:  calc the flags
 * @buffer_chars: the buffer that handel print
 * @the_width: the Width
 * @the_size: the Size
 *
 * Return: Numbers of printed chars
 */
int print_binary(va_list types, char buffer_chars[], int the_flags,
		int the_width, int the_size, int the_precision)
{
	unsigned int i, n, sum, m;
	unsigned int a[32];
	int count;

	UNUSED(buffer_chars);
	UNUSED(the_flags);
	UNUSED(the_width);
	UNUSED(the_precision);
	UNUSED(the_size);

	n = va_arg(types, unsigned int);
	/* the total of 2^31 = 2147483648*/
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
