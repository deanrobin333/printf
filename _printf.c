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
	int printed_characters;

	specifier_t specifiers[] = {
		{'c', handle_c}, {'s', handle_s}, {'%', handle_percent},
		{'d', handle_d}, {'i', handle_i},
		{'b', handle_b},
		{'u', handle_u}, {'o', handle_o}, {'x', handle_x}, {'X', handle_X},
		{'S', handle_S},
		{'p', handle_p},
		{0, NULL}
	};

	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	printed_characters = code_analyzer(format, specifiers, args);
	va_end(args);
	return (printed_characters);
}

