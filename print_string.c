#include "main.h"

/**
 * print_string - prints the string
 * @s: the string to be printed
 * @char_count: the number of chars printed so far
 *
 * Return: void
 */
void print_string(char *s, int char_count)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
		char_count++;
	}
}
