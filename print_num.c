#include "main.h"
#include <stdarg.h>
#include <string.h>

#define MAXBUF (1024)

/**
 * print_num2 - second half of print_num function
 * @sign_char: sign character
 * @char_count: character count
 * @i: index
 * @inc: increment
 * @length: length
 * @ladjust: left align
 * @padc: padding character
 * @buf: buf
 * @p: p
 * @prefix: prefix
 *
 * Return: void
 */
void print_num2(char sign_char, int *char_count, int *i, int inc,
		int length, int ladjust, char padc,
		char *buf, char *p,
		char *prefix)
{
	if (sign_char)
	{
		_putchar(sign_char);
		(*char_count)++;
	}
	if (prefix)
		while (*prefix)
		{
			_putchar(*prefix++);
			(*char_count)++;
		}
	if (padc == '0')
		while (--length >= 0)
		{
			_putchar('0');
			(*char_count)++;
		}
	while (++p != &buf[MAXBUF])
	{
		_putchar(*p);
		(*char_count)++;
	}
	if (ladjust)
	{
		while (--length >= 0)
		{
			_putchar(' ');
			(*char_count)++;
		}
	}
	*i += inc;
}
/**
 * print_num - prints a long number
 * @u: the long number
 * @sign_char: the sign
 * @base: the base
 * @char_count: the char count
 * @i: the index
 * @inc: the increment
 * @truncate: truncate boolean
 * @altfmt: alternate format for hex
 * @capitals: uppercase
 * @length: length
 * @ladjust: left adjust
 * @padc: padding character
 *
 * Return: void
 */
void print_num(unsigned long u, char sign_char, int base, int *char_count,
		int *i, int inc, int truncate, int altfmt, int capitals, int length,
		int ladjust, char padc)
{
	char buf[MAXBUF];

	register char *p = &buf[MAXBUF - 1];
	static const char digits[] = "0123456789abcdef0123456789ABCDEF";
	char *prefix = 0;

	if (truncate)
		u = (long)((int)(u));
	if (u != 0 && altfmt)
	{
		if (base == 8)
			prefix = "0";
		else if (base == 16)
			prefix = "0x";
	}
	do {
		*p-- = digits[(u % base) + capitals];
		u /= base;
	} while (u != 0);
	length -= (&buf[MAXBUF - 1] - p);
	if (sign_char)
		length--;
	if (prefix)
		length -= strlen((const char *) prefix);
	if (padc == ' ' && !ladjust)
	{
		while (--length >= 0)
		{
			_putchar(' ');
			(*char_count)++;
		}
	}
	print_num2(sign_char, char_count, i, inc, length, ladjust,
			padc, buf, p, prefix);
}

/**
 * print_signed - prints a signed numeber
 * @ap: the va_list
 * @sign_char: sign char
 * @plus_sign: plus sign
 * @base: base
 * @char_count: char count
 * @i: index
 * @inc: increment
 * @truncate: truncate boolean
 * @altfmt: alternate format boolean
 * @capitals: uppercase boolean
 * @length: length
 * @ladjust: left justify
 * @padc: padding character
 *
 * Return: void
 */
void print_signed_int(va_list *ap, int sign_char, int plus_sign, int base,
		int *char_count, int *i, int inc, int truncate, int altfmt,
		int capitals, int length, int ladjust, char padc)
{
	unsigned long u;
	long n;

	n = va_arg(*ap, long);
	if (n >= 0)
	{
		u = n;
		sign_char = plus_sign;
	}
	else
	{
		u = -n;
		sign_char = '-';
	}
	print_num(u, sign_char, base, char_count, i, inc, truncate,
			altfmt, capitals, length, ladjust, padc);
}

/**
 * print_unsigned - prints an unsigned number
 * @ap: the va_list
 * @sign_char: sign char
 * @base: the base
 * @char_count: char count
 * @i: index
 * @inc: increment
 * @truncate: truncate boolean
 * @altfmt: alternate format boolean
 * @capitals: uppercase boolean
 * @length: length
 * @ladjust: left justify
 * @padc: padding character
 *
 * Return: void
 */
void print_unsigned_int(va_list *ap, int sign_char, int base,
		int *char_count, int *i, int inc, int truncate, int altfmt,
		int capitals, int length, int ladjust, char padc)
{
	unsigned long int u = va_arg(*ap, unsigned long);

	print_num(u, sign_char, base, char_count, i, inc, truncate, altfmt,
			capitals, length, ladjust, padc);
}
