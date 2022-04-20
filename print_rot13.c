#include "main.h"
#include <stddef.h>

/**
 * print_rot13ed - prints a rot13'ed string
 * @s: the string to be printed
 * @char_count: the chars printed count
 *
 * Return: void
 */
void print_rot13ed(char *s, int *char_count)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (97 <= (int)s[i] && (int)s[i] <= 122)
		{
			if ((int)s[i] <= 109)
			{
				_putchar((int)s[i] + 13);
				(*char_count)++;
			}
			else
			{
				_putchar((int)s[i] - 13);
				(*char_count)++;
			}
		}
		else if (65 <= (int)s[i] && (int)s[i] <= 90)
		{
			if ((int)s[i] <= 77)
			{
				_putchar((int)s[i] + 13);
				(*char_count)++;
			}
			else
			{
				_putchar((int)s[i] - 13);
				(*char_count)++;
			}
		}
		else
		{
			_putchar(s[i]);
			(*char_count)++;
		}
	}
}

/**
 * process_print_rot13ed - processes a print_rot13ed call
 * @s: the string
 * @char_count: the char count
 * @i: the index
 * @inc: the value the index is to be incremented by
 *
 * Return: void
 */
void process_print_rot13ed(char *s, int *char_count, int *i, int inc)
{
	if (s == NULL)
		s = "(null)";
	print_rot13ed(s, char_count);
	*i += inc;
}
