#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: format
 * @...: variable functions
 * Return: count
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	int res = handle_format_specifier(&format, args);

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			++format;
			if (res < 0)
			{
				va_end(args);
				return (-1);
			}
			else
			{
				count += res;
			}
		}
		else
		{
			_putchar(*format);
			++count;
		}
		++format;
	}
	va_end(args);
	return (count);
}
