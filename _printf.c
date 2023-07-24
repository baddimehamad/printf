#include "main.h"
/**
 * _printf - Custom implementation of printf function with C
 * @format: Format string
 *
 * Return: Number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
int i = 0, count = 0;
va_list args;

va_start(args, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
{
count += _putchar((char)va_arg(args, int));
break;
}
case 's':
{
count += _putstr((char *)va_arg(args, char *));
break;
}
case 'd':
case 'i':
{
count += _putnum(va_arg(args, int));
break;
}
default:
count += _putchar(format[i]);
break;
}
}
else
{
_putchar(format[i]);
count++;
}
}
va_end(args);
return (count);
}
