/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:16:54 by acoinus           #+#    #+#             */
/*   Updated: 2022/02/15 14:37:44 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int    display_singlechar(char c)
{
    write (1, &c, 1);
    return (1);
}

int    display_str(const char *c)
{
    int    i;

    i = 0;
    if (!*c)
        return (0);
    while (*c)
    {
        display_singlechar(*c);
        i++;
        c++;
    }
    return (i);
}

int    manage_hexa(unsigned int argument, int nb_chars)
{
    char            *base_hexa;
    unsigned int    num;

    base_hexa = "0123456789abcdef";
    num = argument;
    if (num / 16 > 0)
        nb_chars = manage_hexa(num / 16, nb_chars);
    nb_chars += display_singlechar(base_hexa[num % 16]);
    return (nb_chars);
}

int    manage_int(int argument, int nb_chars)
{
    long int    i;

    i = argument;
    if (argument < 0)
    {
        nb_chars += display_singlechar('-');
        i = i * (-1);
    }
    if (i / 10 > 0)
    {
        nb_chars = manage_int(i / 10, nb_chars);
    }
    nb_chars += display_singlechar(i % 10 + 48);
    return (nb_chars);
}

int    manage_str(char *str, int nb_chars)
{
    if (!str)
        str = "(null)";
    nb_chars += display_str(str);
    return (nb_chars);
}

int    manage_flags(const char    *format, va_list arguments, int nb_chars)
{
    if (*format == 's')
        nb_chars = manage_str(va_arg(arguments, char *), nb_chars);
    if (*format == 'd')
        nb_chars = manage_int(va_arg(arguments, int), nb_chars);
    if (*format == 'x')
        nb_chars = manage_hexa(va_arg(arguments, unsigned int), nb_chars);
    return (nb_chars);
}

int    ft_printf(const char *format, ...)
{
    va_list    arguments;
    int        nb_chars;

    nb_chars = 0;
    va_start(arguments, format);
    while (*format)
    {
        if (*format != '%')
            nb_chars += display_singlechar(*format);
        else
            nb_chars = manage_flags(++format, arguments, nb_chars);
        format++;
    }
    return (nb_chars);
}
