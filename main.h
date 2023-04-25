#ifndef _PRINTF_FUNCTION_
#define _PRINTF_FUNCTION_

typedef struct specifier
{
    char spec;
    int (*f)(va_list);
} specifier_t;

int _putchar(char c);
int _printf(const char *format, ...);
void _vprintf(char *format, va_list args);
int handle_c(va_list);
int handle_s(va_list args);
int handle_percent(va_list);
int handle_number(va_list);
int handle_d(va_list args);
int handle_i(va_list args);

#endif
