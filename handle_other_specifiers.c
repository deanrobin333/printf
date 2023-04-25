#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * handle_u - handle format specifier "u"
 * @args: va_list containing the unsigned integer to print
 * Return: number of characters printed
 */
int handle_u(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int check = 1;
	int length = 0;

	for (; num / check > 9; )
		check *= 10;

	for (; check != 0; )
	{
		length += _putchar('0' + num / check);
		num %= check;
		check /= 10;
	}

	return (length);
}

/**
 * handle_o - handle format specifier "o"
 * @args: va_list containing the unsigned integer to print
 * Return: number of characters printed
 */
int handle_o(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int check = 1;
	int length = 0;

	for (; num / check > 7; )
		check *= 8;

	for (; check != 0; )
	{
		length += _putchar('0' + num / check);
		num %= check;
		check /= 8;
	}

	return (length);
}

/**
 * handle_x - handle format specifier "x"
 * @args: va_list containing the unsigned integer to print
 * Return: number of characters printed
 */
int handle_x(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int length = 0;
	char hex[16] = "0123456789abcdef";

	if (num / 16)
		length += handle_x(args);

	length += _putchar(hex[num % 16]);

	return (length);
}

/**
 * handle_X - handle format specifier "X"
 * @args: va_list containing the unsigned integer to print
 * Return: number of characters printed
 */
int handle_X(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int length = 0;
	char hex[16] = "0123456789ABCDEF";

	if (num / 16)
		length += handle_X(args);

	length += _putchar(hex[num % 16]);

	return (length);
}

