#include "main.h"
#define MAXBUF (1024)

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
void print_base(unsigned int u, int base,
		int *char_count, int *i, int inc)
{
	char buf[MAXBUF];

	char *p = &buf[MAXBUF - 1];
	static const char digits[] = "01";

	do {
		*p-- = digits[u % base];
		u /= base;
	} while (u != 0);

	while (++p != &buf[MAXBUF])
	{
		_putchar(*p);
		(*char_count) += 1;
	}
	*i += inc;
}
