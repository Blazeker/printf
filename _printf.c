#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "holberton.h"
/**
*escape - A simply function of printf
*@format : The format of incoming formats
*@i: integer
*Return: the number of elements printed
*/
int escape(const char *format, int i)
{
	if ((format[i] == 92 || format[i] == 34
		|| format[i] == 39) && format[i] != '\0')
	{
		write(1, &format[i], 1);
		return (i);
	}
	if (format[i] == 37 && format[i + 1] == 37)
	{
		write(1, &format[i], 1);
		return (i + 1);
	}
	if (format[i] == 10)
	{
		write(1, &format[i], 1);
		return (i);
	}
	return (i);
}
/**
*plus - A simply function of printf
*@format : The format of incoming formats
*@i: integer
*Return: the number of elements printed
*/
int plus(const char *format, int i)
{
	if (format[i] != '\0' && format[i] != 92 && format[i] != 37 && format[i]
	 != 34 && format[i] != 39 && format[i] != 10)
	{
		write(1, &format[i], 1);
		return (1);
	}
	else if (format[i] == '\0')
		return (0);
	if (format[i] == 10)
		return (1);
	if (format[i] == 37 && format[i - 1] == 37)
	{
		return (1);
	}
	if (format[i] == 37 && format[i - 1] != 37 && (format[i + 1] != 37 ||
		format[i + 1] != '\0' || format[i + 1] != 'c' || format[i + 1] != 's' ||
		format[i + 1] != 'd' || format[i + 1] != 'i' || format[i + 1] != 'b' ||
		format[i + 1] != 'r'))
	{
		write(1, &format[i], 1);
		return (1);
	}
	return (1);
}
/**
**_printf - A simply function of printf
*@format : The format of incoming formats
*Return: the number of elements printed
*/
int _printf(const char *format, ...)
{
	int i = 0, s = 0, cont;
	char f = '0';
	va_list args;

	va_start(args, format);
	if (format == NULL || (format[i] == 37 && format[i + 1] == '\0'))
		return (-1);
	for (i = 0; format[i]; i++)
	{ i = escape(format, i);
		if (((format[i] == 37) && (format[i + 1] == 'd' || format[i + 1] == 'i' ||
					   format[i + 1] == 'c' || format[i + 1] == 's' ||
					   format[i + 1] == 'b' || format[i + 1] == 'r')))
		{
			if (format[i + 1] == 's' || format[i + 1] == 'r')
				s += switche_string(format[i + 1], va_arg(args, char *));
			else
			{ cont = va_arg(args, int);
				if (format[i + 1] == 'd' || format[i + 1] == 'i' || format[i + 1] == 'b')
				{
					if (cont == 0)
					{ write(1, &f, 1);
					s += 1;
					}
					else
					s += switche_int(format[i + 1], cont);
				} else
					s += switche_int(format[i + 1], cont);
			} i++;
		} else
		{
			if (plus(format, i))
				s++;
			else
				break;
		}
		if (format[i] == 37 && format[i - 1] != 37 && format[i + 1] == '\0')
			return (-1);
	} va_end(args);
	return (s);
}
