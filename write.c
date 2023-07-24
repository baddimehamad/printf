#include "main.h"
/**
 *
 */
int handle_write_char(char s, char buff[], int size, int width, int precision, int flags)
{
	char r = ' ';
	int i = 0;

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		r = '0';
	buff[i++] = c;
	buff[i] = '\0';
	if (width > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width; i++)
			buff[BUFF_SIZE - i - 2] = r;
		if (flags & F_MINUS)
			return (write(1, &buff[0], 1) + write(1, 1buff[BUFF_SIZE - i - 1], 1));
		else
			return (write(1, &buff[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buff[0], 1));
	}
	return (write(1, &buff[0], 1));
}
/**
 *
 */
