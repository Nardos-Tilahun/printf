#include "main.h"

/**
 * _printf - produce output according to a format
 * @format: constant character pointer for format
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0, strlength;
	char temp, *strtemp;
	va_list print_args;

	if (format == NULL)
		return (-1);
	va_start(print_args, format);
	for (; *format != '\0'; format++)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
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
		}
		va_end(print_args);
		return (count);
	}
}
