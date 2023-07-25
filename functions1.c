#include "main.h"
/**
 * print_octal - this function prints unsined nmber in octal
 * @precision: specify the Precision
 * @types: the arguments
 * @flags:  calc the flags
 * @buffer: the buffer that handel print
 * @width: the Width
 * @size: the Size
 * Return: value
 */
int print_octal(va_list types, char buffer_chars[], int the_flags,  int the_width,int the_size, int the_precision)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(the_width);

	num = convert_size_unsgnd(num, the_size);

	if (num == 0)
		buffer_chars[i--] = '0';

	buffer_chars[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer_chars[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (the_flags & F_HASH && init_num != 0)
		buffer_chars[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer_chars, the_flags, the_width, the_precision, the_size));
}

/**
 * print_hexadecimal - this function prints unsined numbers in hexadecimal
 * @precision: specify the Precision
 * @types: the arguments
 * @flags:  calc the flags
 * @buffer: the buffer that handel print
 * @width: the Width
 * @size: the Size
 * Return: value
 */
int print_hexadecimal(va_list types, char buffer_chars[], int the_flags,  int the_width,int the_size, int the_precision)
{
	return (print_hexa(types, "0123456789abcdef", buffer_chars,the_flags, 'x', the_width, the_precision, the_size));
}
/**
 * print_hexa_upper - this function prints the unsined numbers in the upper hexadecimal 
 * @precision: specify the Precision
 * @types: the arguments
 * @flags:  calc the flags
 * @buffer: the buffer that handel print
 * @width: the Width
 * @size: the Size
 * Return: value
 */
int print_hexa_upper(va_list types, char buffer_chars[], int the_flags,  int the_width,int the_size, int the_precision)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer_chars,the_flags, 'X', the_width, the_precision, the_size));
}
/**
 * print_unsigned - this function print nsined numbers
 * @precision: specify the Precision
 * @types: the arguments
 * @flags:  calc the flags
 * @buffer: the buffer that handel print
 * @width: the Width
 * @size: the Size
 * Return: value
 */
int print_unsigned(va_list types, char buffer_chars[], int the_flags,  int the_width,int the_size, int the_precision)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, the_size);

	if (num == 0)
		buffer_chars[i--] = '0';

	buffer_chars[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer_chars[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer_chars, the_flags, the_width, the_precision, the_size));
}


/**
 * print_hexa - this function prints the unsined numbers in hexadecimal lower or upper
 * @precision: specify the Precision
 * @types: the arguments
 * @flags:  calc the flags
 * @buffer: the buffer that handel print
 * @width: the Width
 * @size: the Size
 * @map_to: Array of values to map the number to
 * @flag_ch: Calculates active flags
 * Return: value
 */
int print_hexa(va_list types, char map_to[], char buffer_chars[],int the_flags, char the_flag_ch, int the_width, int the_precision, int the_size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(the_width);

	num = convert_size_unsgnd(num, the_size);

	if (num == 0){
		buffer_chars[i--] = '0';
	}

	buffer_chars[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer_chars[i--] = map_to[num % 16];
		num /= 16;
	}

	if (the_flags & F_HASH && init_num != 0)
	{
		buffer_chars[i--] = the_flag_ch;
		buffer_chars[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer_chars, the_flags, the_width, the_precision, the_size));
}
