#include "main.h"
#include <stdarg.h>
#include <stddef.h>

#define isdigit(d) ((d) >= '0' && (d) <= '9')
#define ctod(c) ((c) - '0')

/**
 * do_printf - processes the formatted printing
 * @format: the format string
 * @ap: the va_list list of arguments
 *
 * Return: the number of characters printed
 */
int do_printf(const char *format, va_list *ap)
{
	int i, j, char_count, length, prec, ladjust, plus_sign, sign_char,
	    altfmt, truncate, capitals, is_cstm;
	char padc;
	char non_cstm[] = "csdibuoxXp";

	is_cstm = 1;
	char_count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			process_putchar(format[i], &char_count, &i, 1);
			continue;
		}
		i++;
		if (format[i] == '%')
		{
			process_putchar('%', &char_count, &i, 1);
			continue;
		}
		length = 0;
		prec = -1;
		ladjust = 0;
		padc = ' ';
		plus_sign = 0;
		sign_char = 0;
		altfmt = 0;

		while (1)
		{
			if (format[i] == '#')
				altfmt = 1;
			else if (format[i] == '-')
				ladjust = 1;
			else if (format[i] == '+')
				plus_sign = '+';
			else if (format[i] == ' ')
			{
				if (plus_sign == 0)
					plus_sign = ' ';
			}
			else
				break;
			i++;
		}
		if (format[i] == '0')
		{
			padc = '0';
			i++;
		}
		if (isdigit(format[i]))
		{
			while (isdigit(format[i]))
			{
				length = 10 * length + ctod(format[i]);
				i++;
			}
		}
		else if (format[i] == '*')
		{
			length = va_arg(*ap, int);
			i++;
			if (length < 0)
			{
				ladjust = !ladjust;
				length = -length;
			}
		}
		if (format[i] == '.')
		{
			i++;
			if (isdigit(format[i]))
			{
				prec = 0;
				while (isdigit(format[i]))
				{
					prec = 10 * prec + ctod(format[i]);
					i++;
				}
			}
			else if (format[i] == '*')
			{
				prec = va_arg(*ap, int);
				i++;
			}
		}
		if (format[i] == 'l')
			i++;
		truncate = 0;
		capitals = 0;

		for (j = 0; non_cstm[j] != '\0'; j++)
		{
			if (format[i] == non_cstm[j])
				is_cstm = 0;
		}
		if (is_cstm == 1)
		{
			altfmt = 0;
			plus_sign = 0;
		}
		switch (format[i])
		{
			case 'b':
				print_base(va_arg(*ap, int), 2, &char_count, &i, 1);
				break;
			case 'c':
				process_putchar(va_arg(*ap, int), &char_count, &i, 1);
				break;
			case 's':
				process_print_string(va_arg(*ap, char *), &char_count, &i, 1);
				break;
			case 'S':
				process_print_String(va_arg(*ap, char *), &char_count, &i, 1);
				break;
			case 'd':
			case 'i':
				process_print_number(va_arg(*ap, int), &char_count, &i, 1);
				break;
			case 'o':
			case 'O':
				print_unsigned_int(ap, sign_char, 8, &char_count, &i, 1,
						truncate, altfmt, capitals, length, ladjust, padc);
				break;
			case 'u':
			case 'U':
				print_unsigned_int(ap, sign_char, 10, &char_count, &i, 1,
						truncate, altfmt, capitals, length, ladjust, padc);
				break;
			case 'p':
			case 'x':
				altfmt = (format[i] == 'p' ? 1 : altfmt);
				print_unsigned_int(ap, sign_char, 16, &char_count, &i, 1,
						truncate, altfmt, capitals, length, ladjust, padc);
				break;
			case 'X':
				print_unsigned_int(ap, sign_char, 16, &char_count, &i, 1,
						truncate, altfmt, 16, length, ladjust, padc);
				break;
			case '\0':
				i--;
				break;
			default:
				process_putchar(format[i - 1], &char_count, &i, 0);
				process_putchar(format[i], &char_count, &i, 1);
		}
	}
	return (char_count);
}


/**
 * _printf - a printf function
 * @format: the format
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int char_count;
	va_list ap;

	va_start(ap, format);
	char_count = do_printf(format, &ap);
	va_end(ap);
	return (char_count);
}
