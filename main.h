#ifndef _PRINTF_FUNCTION_
#define _PRINTF_FUNCTION_

/**
 * struct specifier - struct containing a specifier
 * @spec: the specifier
 * @f: the function
 */
typedef struct specifier
{
	char spec;
	int (*f)(va_list);
} specifier_t;

int _putchar(char c);
int _printf(const char *format, ...);
int handle_c(va_list args);
int handle_s(va_list args);
int handle_percent(va_list args);
int handle_number(va_list);
int handle_d(va_list args);
int handle_i(va_list args);
int handle_binary(va_list args);
int handle_b(va_list args);
int handle_u(va_list args);
int handle_o(va_list args);
int handle_x(va_list args);
int handle_X(va_list args);

#endif
