#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_c - prints a single character
 * @args: the list of arguments
 * Return: the number of characters printed
 */
int handle_c(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * handle_s - prints a string
 * @args: the list of arguments
 * Return: the number of characters printed
 */
int handle_s(va_list args)
{
	char *str = va_arg(args, char *);
	int i;

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * handle_percent - prints a percent symbol
 * @args: the list of arguments (unused)
 *
 * Return: the number of characters printed (always 1)
 */
int handle_percent(__attribute__((unused))va_list args)
{
	_putchar('%');
	return (1);
}

