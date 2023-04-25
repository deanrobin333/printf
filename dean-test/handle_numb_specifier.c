#include <stdio.h>
#include <stdarg.h>
#include "main.h"


/**
 * handle_number - helper function to print an integer
 * @args: arguments
 * Return: number of characters printed
 */

int handle_number(va_list args)
{
	int i;
	int check;
	int length;
	unsigned int num;

	i = va_arg(args, int);
	check = 1;
	length = 0;

	if (i < 0)
	{
		length += _putchar('-');
		num = i * -1;
	}
	else
		num = i;

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
 * handle_d - handle format specifier "d"
 * @args: va_list containing the integer to print
 * Return: number of characters printed
 */
int handle_d(va_list args)
{
	int n;

	n = handle_number(args);
	return (n);

}
/**
 * handle_i - handle format specifier "i"
 * @args: va_list containing the integer to print
 * Return: number of characters printed
 */
int handle_i(va_list args)
{
	return (handle_d(args));
}

