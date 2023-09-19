#include "main.h"

/**
 * handle_conv - handle the conversion specifier
 * @format: constant character pointer for format
 * @print_args : variadic list of arguments
 * Return: the number of characters printed
 */
int handle_conv(const char *format, va_list print_args)
{
	int count = 0, strlength = 0;
	char temp, *strtemp;

	if (*format == '\0')
		return (-1);
	if (*format == 'c')
	{
		temp = va_arg(print_args, int);
		write(1, &temp, 1);
		count++;
	}
	if (*format == 's')
	{
		strtemp = va_arg(print_args, char *);
		for (; *strtemp != '\0' && strtemp != NULL; strlength++, strtemp++)
			write(1, strtemp, 1);
		count += strlength;
	}
	if (*format == '%')
	{
		write(1, format, 1);
		count++;
	}
	return (count);
}

/**
 * _printf - produce output according to a format
 * @format: constant character pointer for format
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list print_args;

	if (format == NULL)
		return (-1);
	va_start(print_args, format);
	for (; (*format != '\0'); format++)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			count += handle_conv(format, print_args);
		}
	}
	va_end(print_args);
	return (count);
}
