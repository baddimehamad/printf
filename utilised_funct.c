#include "main.h"

/**
 * is_printable - checks if a char is printable
 * @s: the char to check
 *
 * Return: 1 if the char is printable else 0
 */
int is_printable(char s)
{
	if (s >= 32 && s < 127)
		return (1);
	return (0);
}
/**
 * append_hexa_code - append ascci in hexadecimal code to buffer
 * @ascii: the ASSCI code that gonna be append
 * @buff: array of chars
 * @i: Index at which to start appending.
 *
 * Return: always 3 (Success)
 */
int append_hexa_code(char ascii, char buff[], int i)
{
	char map_to[] = "0123456789ABCDE";

	if (ascii < 0)
		ascii *= -1;
	buff[i++] = '\\';
	buff[i++] = 'x';
	buff[i++] = map_to[ascii / 16];
	buff[i] = map_to[ascii % 16];
	return (3);
}
/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @n: the unsigned number to be casted
 * @size: the type to be casted
 *
 * Return: casted value of number
 */
long int convert_size_unsgnd(unsigned long int n, int size)
{
	if (size == S_LONG)
		return (n);
	else if (size == S_SHORT)
		return ((unsigned short)n);
	return ((unsigned int)n);
}
/**
 * convert_size_number - casts a number to the specified size
 * @n: the number to be casted
 * @size: the type to be casted
 *
 * Return: casted value of number
 */
long int convert_size_number(long int n, int size)
{
	if (size == S_LONG)
		return (n);
	else if (size == S_SHORT)
		return ((short)n);
	return ((int)n);
}
/**
 * is_digit - checks if a char is a digit
 * @s: the char to be evaluated
 *
 * Return: 1 if sis a digit else 0
 */
int is_digit(char s)
{
	if (s >= '0' && s <= '9')
		return (1);
	return (0);
}
