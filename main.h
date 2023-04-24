#ifndef _PRINTF_FUNCTION_
#define _PRINTF_FUNCTION_

int _putchar(char c);
int _printf(const char *format, ...);
int handle_format_specifier(const char **format_ptr, va_list args);


#endif
