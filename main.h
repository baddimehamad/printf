#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>

/* get length  */
int getlen(char *f);

/* string reverse */
void _strrev(char *str);

/* itoa */
char *_itoa(int value, char *str, int base);

/* putchar string */
int _putchar(char c);

/* putstr string */
int _putstr(char *c);

/* putnum  numero*/
int _putnum(int c);

/* printf string */
int _printf(const char *format, ...);

#endif
