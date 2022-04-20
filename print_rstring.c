#include "main.h"

/**
 * print_rstring - prints a string in reverse
 * @s: the string to be printed
 * @char_count: the chars printed count
 *
 * Return: void
 */
void print_rstring(char *s, int *char_count)
{
	int i, count;

	count = 0;
	for (i = 0; s[i] != '\0'; i++)
		count++;
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(s[i]);
		(*char_count)++;
	}
}
