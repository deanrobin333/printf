#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_S - prints a string and converts non-printable characters to hex
 * @args: the list of arguments
 * Return: the number of characters printed
 */
int handle_S(va_list args)
{
	char *str = va_arg(args, char *);
	int i, count = 0;

	if (str == NULL)
	{
		str = "(null)";
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			char hex_digits[3];
			sprintf(hex_digits, "%02X", (unsigned char)str[i]);
			putchar('\\');
			putchar('x');
			putchar(hex_digits[0]);
			putchar(hex_digits[1]);
			count += 4;
		}
		else
		{
			putchar(str[i]);
			count++;
		}
	}

	putchar('\n');
	count++;

	return count;
}

