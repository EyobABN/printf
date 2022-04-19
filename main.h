#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
void print_string(char *s, int *char_count);
void print_String(char *s, int *char_count);
void print_number(int n, int *char_count);
void print_num(unsigned long u, char sign_char, int base,
		int *char_count, int *i, int inc, int truncate, int altfmt,
		int capitals, int length, int ladjust, char padc);
void print_base(register unsigned int u, register int base,
		int *char_count, int *i, int inc);
void print_signed_int(va_list *ap, int sign_char, int plus_sign,
		int base, int *char_count, int *i, int inc, int truncate,
		int altfmt, int capitals, int length, int ladjust, char padc);
void print_unsigned_int(va_list *ap, int sign_char, int base,
		int *char_count, int *i, int inc, int truncate, int altfmt,
		int capitals, int length, int ladjust, char padc);
void process_putchar(char c, int *char_count, int *i, int inc);
void process_print_string(char *s, int *char_count, int *i, int inc);
void process_print_String(char *s, int *char_count, int *i, int inc);
void process_print_number(int n, int *char_count, int *i, int inc);

#endif /* MAIN_H */
