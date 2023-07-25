#include "main.h"
/**
 * get_flags - handles active flags
 * @format: formatted string
 * @p: a parameter
 *
 * Return: flags
 */
int get_flags(const char *format, int *p)
{
	const char FLAGS_C = {'0', '+', '-', ' ', '#', '\0'};
	const int FAGS_AR = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	int i, pi, flag = 0;

	for (pi = *p + 1; format[pi] != '\0'; pi++)
	{
		for (i = 0; FLAGS_C[i] != '\0'; i++)
		{
			if (format[pi] == FLAGS_C[i])
			{
				flag |= FLAGS_AR[i];
				break;
			}
			if (FLAGS_C[i] == 0)
				break;
		}
	}
	*p = pi - 1;
	return (flag);
}
