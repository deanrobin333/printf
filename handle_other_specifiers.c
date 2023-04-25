#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>
#include <unistd.h>

int write_hex(unsigned long int num, const char *map_to, char flag_ch);
/**
 * handle_u - handle format specifier "u"
 * @args: va_list containing the unsigned integer to print
 * Return: number of characters printed
 */
int handle_u(va_list args)
{
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int check = 1;
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
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int check = 1;
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
	unsigned long int num = va_arg(args, unsigned long int);

	return (write_hex(num, HEX_LOWER, 'x'));
}
/**
 * handle_X - handle format specifier "X"
 * @args: va_list containing the unsigned integer to print
 * Return: number of characters printed
 */

int handle_X(va_list args)
{
	unsigned long int num = va_arg(args, unsigned long int);

	return (write_hex(num, HEX_UPPER, 'X'));
}

/**
 * write_hex - Converts an unsigned long int to a hexadecimal
 * @num: The unsigned long integer to convert to hexadecimal.
 * @map_to: A string containing the mapping of digits to characters.
 * @flag_ch: The flag character to prepend to the output, or '\0' if none
 * Return: The number of characters written to standard output.
 */
int write_hex(unsigned long int num, const char *map_to, char flag_ch)
{
	int count = 0;

	char buffer[sizeof(unsigned long int) * 2 + 1];
	char *ptr = buffer + sizeof(buffer) - 1;
	*ptr = '\0';

	do {
		*--ptr = map_to[num % 16];
		num /= 16;
		count++;
	} while (num != 0);

	if (flag_ch != '\0')
	{
		*--ptr = flag_ch;
		*--ptr = '0';
		count += 2;
	}
	return write(STDOUT_FILENO, ptr, sizeof(buffer) - (ptr - buffer)) == -1
		? -1
		: count;


}
