#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * process_putchar - processes a _putchar call
 * @c: the character to be written
 * @char_count: the character count so far
 * @i: the index
 * @inc: the value the index is to be incremented by
 *
 * Return: void
 */
void process_putchar(char c, int *char_count, int *i, int inc)
{
	_putchar(c);
	(*char_count)++;
	*i += inc;
}

/**
 * process_print_string - handles printing with the print_string
 * @s: the string
 * @char_count: the char count so far
 * @i: the index so far
 * @inc: the value the index is to be incremented by
 *
 * Return: void
 */
void process_print_string(char *s, int *char_count, int *i, int inc)
{
		if (s == NULL)
			s = "(null)";
		print_string(s, char_count);
		*i += inc;
}

/**
 * process_print_number - processes the print_number function
 * @n: the number to be printed
 * @char_count: the char count so far
 * @i: the index so far
 * @inc: the value the index is to be incremented by
 *
 * Return: void
 */
void process_print_number(int n, int *char_count, int *i, int inc)
{
	print_number(n, char_count);
	*i += inc;
}

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

	va_start(ap, format);
	char_count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				process_putchar(va_arg(ap, int), &char_count, &i, 2);
			else if (format[i + 1] == '%')
				process_putchar('%', &char_count, &i, 2);
			else if (format[i + 1] == 's')
				process_print_string(va_arg(ap, char *), &char_count, &i, 2);
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				process_print_number(va_arg(ap, int), &char_count, &i, 2);
			else
				process_putchar(format[i], &char_count, &i, 1);
		}
		else
			process_putchar(format[i], &char_count, &i, 1);
	}
	va_end(ap);
	return (char_count);
}
