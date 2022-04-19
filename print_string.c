#include "main.h"

/**
 * print_string - prints a string
 * @s: the string to be printed
 * @char_count: the chars printed count
 *
 * Return: void
 */
void print_string(char *s, int *char_count)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
		(*char_count)++;
	}
}

/**
 * print_String - prints the string for S conversion specifier
 * @s: the string to be printed
 * @char_count: the number of chars printed so far
 *
 * Return: void
 */
void print_String(char *s, int *char_count)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if ((0 < (int)s[i] && (int)s[i] < 32) || (int)s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			_printf("%02X", (int)s[i]);
			(*char_count) += 4;
		}
		else
		{
			_putchar(s[i]);
			(*char_count)++;
		}
	}
}
