#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * handle_binary - helper function to print a binary number
 * @args: arguments
 * Return: number of characters printed
 */

int handle_binary(va_list args)
{
	unsigned int num;
	int i, j, bin[32], length;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (_putchar('0'));

	for (i = 0; num > 0; i++)
	{
		bin[i] = num % 2;
		num /= 2;
	}

	length = i;

	for (j = i - 1; j >= 0; j--)
		_putchar(bin[j] + '0');

	return (length);
}

/**
 * handle_b - handle format specifier "b"
 * @args: va_list containing the unsigned int to print in binary
 * Return: number of characters printed
 */
int handle_b(va_list args)
{
	int n;

	n = handle_binary(args);
	return (n);
}

