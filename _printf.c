#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            _putchar(*format);
            count++;
        }
        else
        {
            format++;

            switch (*format)
            {
                case 'c':
                    {
                        int ch = va_arg(args, int);
                        _putchar(ch);
                        count++;
                        break;
                    }
                case 's':
                    {
                        char *str = va_arg(args, char*);
                        while (*str)
                        {
                            _putchar(*str);
                            str++;
                            count++;
                        }
                        break;
                    }
                case '%':
                    _putchar('%');
                    count++;
                    break;
                default:
                    _putchar('%');
                    _putchar(*format);
                    count += 2;
                    break;
            }
        }

        format++;
    }

    va_end(args);

    return (count);
}

