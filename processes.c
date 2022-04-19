#include "main.h"
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
 * process_print_String - handles printing for the %S conversion specifier
 * @s: the string
 * @char_count: the char count so far
 * @i: the index so far
 * @inc: the value the index is to be incremented by
 *
 * Return: void
 */
void process_print_String(char *s, int *char_count, int *i, int inc)
{
		if (s == NULL)
			s = "(null)";
		print_String(s, char_count);
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
