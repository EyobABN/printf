#include "main.h"
#include <limits.h>

/**
 * print_number - prints an integer recursively using _putchar
 * @n: the integer to be printed
 * @char_count: the number of chars printed so far
 *
 * Return: void
 */
void print_number(int n, int *char_count)
{
	if (n == INT_MIN)
	{
		_putchar('-');
		_putchar('2');
		(*char_count) += 2;
		print_number((INT_MAX % 2000000000) + 1, char_count);
		return;
	}

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		(*char_count)++;
	}
	if (n == 0)
	{
		_putchar('0');
		(*char_count)++;
		return;
	}
	if (n / 10)
		print_number(n / 10, char_count);
	_putchar(n % 10 + '0');
	(*char_count)++;
}
