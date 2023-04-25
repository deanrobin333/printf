#include <stdio.h>
#include <stdarg.h>
#include "main.h"


/**
 * handle_number - helper function to print an integer in a given base
 * @n: integer to print
 * @base: base to print (between 2 and 16)
 * Return: number of characters printed
 */

int handle_number(unsigned int n, unsigned int base)
{
	static const char *const digits = "0123456789ABCDEF";
	char buffer[100];
	int len = 0;

	if (base < 2 || base > 16)
		return (-1);

	do {
		buffer[len++] = digits[n % base];
		n /= base;
	} while (n > 0);

	while (len > 0)
	{
		_putchar(buffer[--len]);
	}

	return (len);
}

/**
 * handle_d - handle format specifier "d"
 * @args: va_list containing the integer to print
 * Return: number of characters printed
 */
int handle_d(va_list args)
{
	int n = va_arg(args, int);
	int len = 0, sign = 1;

	if (n < 0)
	{
		sign = -1;
		len += _putchar('-');
	}

	len += handle_number(n * sign, 10);

	return (len);
}

/**
 * handle_i - handle format specifier "d"
 * @args: va_list containing the integer to print
 * Return: number of characters printed
 */
int handle_i(va_list args)
{
	return (handle_d(args));
}

