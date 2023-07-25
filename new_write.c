#include "main.h"
/**
 * handle_write_char - prints a string
 * @s: char
 * @buff: an array to handle print
 * @size: size specifier
 * @width: width
 * @precision: precision
 * @flags: flags
 *
 * Return: the number of char to prints
 */
int handle_write_char(char s, char buff[],
		int size, int width, int precision, int flags)
{
	char r = ' ';
	int i = 0;

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		r = '0';
	buff[i++] = s;
	buff[i] = '\0';
	if (width > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width; i++)
			buff[BUFF_SIZE - i - 2] = r;
		if (flags & F_MINUS)
			return (write(1, &buff[0], 1)
					+ write(1, &buff[BUFF_SIZE - i - 1], 1));
		else
			return (write(1, &buff[BUFF_SIZE - i - 1], width - 1)
					+ write(1, &buff[0], 1));
	}
	return (write(1, &buff[0], 1));
}
/**
 * write_num - prints a number
 * @i: the index the buffer starts with
 * @buff: an array
 * @flags: the flags
 * @c: an extra char
 * @p: the padding char
 * @len: length
 * @precision: percision
 * @width: width
 *
 * Return: number of printed char
 */
int write_num(int i, char buff[], int flags,
		char c, char p, int len, int precision, int width)
{
	int x, start = 1;

	if (precision == 0 && i == BUFF_SIZE - 2 && buff[i] == '0' && width == 0)
		return (0);
	if (precision == 0 && i == BUFF_SIZE - 2 && buff[i] == '0')
		buff[i] = p = ' ';
	if (precision < len && precision > 0)
		p = ' ';
	while (len < precision)
		buff[--i] = '0', len++;
	if (c != 0)
		len++;
	if (width > len)
	{
		for (x = 1; x < width - len + 1; x++)
			buff[x] = p;
		buff[x] = '\0';
		if ((flags & F_MINUS) && p == ' ')
		{
			if (c)
				buff[--i] = c;
			return (write(1, &buff[i], len) + write(1, &buff[1], x - 1));
		}
		else if (!(flags & F_MINUS) && (p == '0'))
		{
			if (c)
				buff[--start] = c;
			return (write(1, &buff[start], x - start)
					+ write(1, &buff[i], len - (1 - start)));
		}
		else if (!(flags & F_MINUS) && p == ' ')
		{
			if (c)
				buff[--i] = c;
			return (write(1, &buff[1], x - 1) + write(1, &buff[i], len));
		}
	}
	if (c)
		buff[--i] = c;
	return (write(1, &buff[i], len));
}
/**
 * write_pointer - prints memory adress using pointer
 * @i: the index
 * @buff: an array
 * @flags: flags
 * @c: the extra char
 * @p: the padding char
 * @len: length
 * @start: an index the padding start
 * @width: width
 *
 * Return: number of wriren chars
 */
int write_pointer(int i, char buff[], int flags,
		char c, char p, int len, int start, int width)
{
	int x;

	if (len < width)
	{
		for (x = 3; x < width - len + 3; x++)
			buff[x] = p;
		buff[x] = '\0';
		if (!(flags & F_MINUS) && p == ' ')
		{
			buff[--i] = 'x';
			buff[--i] = '0';
			if (c)
				buff[--i] = c;
			return (write(1, &buff[3], x - 3)
					+ write(1, &buff[i], len));
		}
		else if ((flags & F_MINUS) && p == ' ')
		{
			buff[--i] = 'x';
			buff[--i] = '0';
			if (c)
				buff[--i] = c;
			return (write(1, &buff[i], len)
					+ write(1, &buff[3], x - 3));
		}
		else if (!(flags & F_MINUS) && p == '0')
		{
			if (c)
				buff[--start] = c;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[start], x - start)
					+ write(1, &buff[i], len - (1 - start) - 2));
		}
	}
	buff[--i] = 'x';
	buff[--i] = '0';
	if (c)
		buff[--i] = c;
	return (write(1, &buff[i], BUFF_SIZE - i - 1));
}
/**
 * write_number - prints string
 * @is_negative: indicating if a number is negative
 * @i: an index
 * @buff: an array of buffer
 * @flags: flags
 * @precision: precision
 * @size: size
 * @width: width
 *
 * Return: a number of printed chars
 */
int write_number(int is_negative, int i, char buff[], int flags,
		int precision, int size, int width)
{
	char p = ' ', c = 0;
	int len = BUFF_SIZE - i - 1;

	UNUSED(size);
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		p = '0';
	if (is_negative)
		c = '-';
	else if (flags & F_PLUS)
		c = '+';
	else if (flags & F_SPACE)
		c = ' ';
	return (write_num(i, buff, width, flags, precision, len, c, p));
}
/**
 * write_unsgnd - writes an unsigned numbers
 * @is_negative: indicating if a number is negative
 * @ind: index
 * @buff: array
 * @flags: flags
 * @precision: precision
 * @size: size
 * @width: width
 *
 * Return: number of printed chars
 */
int write_unsgnd(int is_negative, int i, char buff[], int flags,
		int precision, int size, int width)
{
	char p = ' ';
	int len = BUFF_SIZE - i - 1;
	int x;

	UNUSED(size);
	UNUSED(is_negative);
	if (precision == 0 && i == BUFF_SIZE - 2 && buff[i] == '0')
		return (0);
	if (precision < len && precision > 0)
		p = ' ';
	while (len < precision)
	{
		buff[--i] = '0';
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		p = '0';
	if (len < width)
	{
		for (x = 0; x < width - len; x++)
			buff[x] = p;
		buff[i] = '0';
		if (flags & F_MINUS)
			return (write(1, &buff[i], len) + write(1, &buff[0], x));
		else
			return (write(1, &buff[0], x) + write(1, &buff[i], len));
	}
	return (write(1, &buff[i], len));
}
