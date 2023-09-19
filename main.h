#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...);
int handle_conv(const char *format, va_list print_args);

#endif
