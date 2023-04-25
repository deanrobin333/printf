#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * code_analyzer - checks characters for correct format specifier
 * acts like a parser program
 * @format: foramt string
 * @specifiers: format specifiers
 * @args: arguments
 * Return: len, which is the characters length
 */
int code_analyzer(const char *format, specifier_t specifiers[], va_list args)
{
	int i, j, len = 0;

	if (format == NULL)
		return (-1);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return (-1);

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
	return (len);
}
