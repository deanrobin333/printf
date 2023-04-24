#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * handle_format_specifier - handles format specifier for _printf function
 * @format_ptr: pointer to format in printf function
 * @args: number of arguments
 * Return: value
 */

int handle_format_specifier(const char **format_ptr, va_list args)
{
	const char *format = *format_ptr;

	if (*format == 'c')
	{
		char c = va_arg(args, int);

		putchar(c);
		return (1);
	}
	else if (*format == 's')
	{
		const char *s = va_arg(args, const char *);

		if (s != NULL)
		{
			int len = 0;

			while (s[len] != '\0')
			{
				++len;
			}
			fwrite(s, sizeof(char), len, stdout);
			return (len);
		}
		else
		{
			fwrite("(null)", sizeof(char), 6, stdout);
			return (6);
		}
	}
	else if (*format == '%')
	{
		_putchar('%');
		return (1);
	}
	else
	{
		return (-1);
	}
}
