#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_u - helper function to print an unsigned integer
 * @args: arguments
 * Return: number of characters printed
 */
int handle_u(va_list args)
{
        unsigned int i, check, length, num;

        i = va_arg(args, unsigned int);
        check = 1;
        length = 0;
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
 * handle_o - handle format specifier "o"
 * @args: va_list containing the unsigned int to print in octal
 * Return: number of characters printed
 */
int handle_o(va_list args)
{
        unsigned int i, length, num, oct[100];

        i = va_arg(args, unsigned int);
        length = 0;
        num = i;

        while (num != 0)
        {
                oct[length] = num % 8;
                num /= 8;
                length++;
        }

        for (; length > 0; length--)
        {
                _putchar(oct[length - 1] + '0');
        }

        return (length);
}

/**
 * handle_x - handle format specifier "x"
 * @args: va_list containing the unsigned int to print in hexadecimal
 * (lowercase letters)
 * Return: number of characters printed
 */
int handle_x(va_list args)
{
        unsigned int i, length, num, hex[100];

        i = va_arg(args, unsigned int);
        length = 0;
        num = i;

        while (num != 0)
        {
                hex[length] = num % 16;
                num /= 16;
                length++;
        }

        for (; length > 0; length--)
        {
                if (hex[length - 1] < 10)
                {
                        _putchar(hex[length - 1] + '0');
                }
                else
                {
                        _putchar(hex[length - 1] + 'W');
                }
        }

        return (length);
}

/**
 * handle_X - handle format specifier "X"
 * @args: va_list containing the unsigned int to print in hexadecimal
 * (uppercase letters)
 * Return: number of characters printed
 */
int handle_X(va_list args)
{
        unsigned int i, length, num, hex[100];

        i = va_arg(args, unsigned int);
        length = 0;
        num = i;

        while (num != 0)
        {
                hex[length] = num % 16;
                num /= 16;
                length++;
        }

        for (; length > 0; length--)
        {
                if (hex[length - 1] < 10)
                {
                        _putchar(hex[length - 1] + '0');
                }
                else
                {
                        _putchar(hex[length - 1] + '7');
                }
        }

        return (length);
}

