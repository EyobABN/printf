#include "main.h"
#define MAXBUF (sizeof(long int) * 8)

/**
 * print_base - prints a number
 * @u: the number
 * @base: the base
 * @char_count: the number of characters printed so far
 * @i: the index so far
 * @inc: the value the index is to be incremented by
 *
 * Return: void
 */
void print_base(register unsigned int u, register int base,
		int *char_count, int *i, int inc)
{
	char buf[MAXBUF];

	register char *p = &buf[MAXBUF - 1];
	static const char digits[] = "0123456789abcdef";

	do {
		*p-- = digits[u % base];
		u /= base;
	} while (u != 0);

	while (++p != &buf[MAXBUF])
	{
		_putchar(*p);
		(*char_count) += 2;
		*i += inc;
	}
}
