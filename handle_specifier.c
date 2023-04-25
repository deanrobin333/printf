#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * handle_char - function that handles characters
 * @c: character
 * @count: iterate
 * Return: void
 */
void handle_char(char c, int *count)
{
	_putchar(c);
	if (count != NULL)
	{
		++(*count);
	}
}

/**
 * handle_string - function that deals with strings.
 * @s: string being handled
 * @len: length of string
 * @count: iterate
 * Return: void
 */

void handle_string(const char *s, int len, int *count)
{
	int i;

	for (i = 0; i < len; ++i)
	{
		_putchar(s[i]);
		if (count != NULL)
		{
			++(*count);
		}
	}
}

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

		handle_char(c, NULL);
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
			handle_string(s, len, NULL);
			return (len);
		}
		else
		{
			handle_string("(null)", 6, NULL);
			return (6);
		}
	}
	else if (*format == '%')
	{
		handle_char('%', NULL);
		return (1);
	}
	else
	{
		return (-1);
	}
}

