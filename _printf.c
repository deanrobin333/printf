#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int i, j, len = 0;

	specifier_t specifiers[] = {
		{'c', handle_c}, {'s', handle_s}, {'%', handle_percent},
		{'d', handle_d}, {'i', handle_i},
		{'b', handle_b},
		{'u', handle_u}, {'o', handle_o}, {'x', handle_x}, {'X', handle_X},
		{0, NULL}
	};

	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; specifiers[j].spec; j++)
			{
				if (format[i + 1] == specifiers[j].spec)
				{
					len += specifiers[j].f(args);
					i++;
					break;
				}
			}
			if (!specifiers[j].spec)
				len += _putchar(format[i]);
		}
		else
			len += _putchar(format[i]);
	}

	va_end(args);
	return (len);
}

