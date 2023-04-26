#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_hex - prints a number in hexadecimal format
 * @num: the number to print
 * @charset: the characters to use for hexadecimal digits
 * Return: the number of characters printed
 */
int print_hex(unsigned long int num, char *charset)
{
	int count = 0;
	char buffer[32];
	int i, j;

	if (num == 0)
	{
		count += _putchar('0');
		return (count);
	}

	for (i = 0; num != 0; i++)
	{
		buffer[i] = charset[num % 16];
		num /= 16;
	}

	count += i;

	for (j = i - 1; j >= 0; j--)
	{
		count += _putchar(buffer[j]);
	}

	return (count);
}

/**
 * handle_p - prints the address of a pointer
 * @args: the list of arguments
 * Return: the number of characters printed
 */
int handle_p(va_list args)
{
	void *ptr = va_arg(args, void *);
	unsigned long int address = (unsigned long int) ptr;
	int count = 0;

	count += _putchar('0');
	count += _putchar('x');
	count += print_hex(address, "0123456789abcdef");

	return (count);
}

