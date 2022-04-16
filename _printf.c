#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * _printf - a printf function
 * @format: the format
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, char_count;
	char *s;

	va_start(ap, format);
	char_count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			_putchar(va_arg(ap, int));
			char_count++;
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			_putchar('%');
			char_count++;
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			print_string(va_arg(ap, char *), &char_count);
			i += 2;
		}
		else if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			print_number(va_arg(ap, int), &char_count);
			i += 2;
		}
		else
		{
			_putchar(format[i]);
			char_count++;
			i++;
		}
	}
	va_end(ap);
	return (char_count);
}
