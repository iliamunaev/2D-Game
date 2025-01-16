/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:28:06 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/08 15:26:33 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Checks if a given character is a valid format specifier for ft_printf.
**
** c: The character to check.
** Return: 1 if the character is a valid specifier, 0 otherwise.
*/

int	in_set(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

/*
** Processes the format specifier and writes the corresponding argument
** to the standard output.
**
** args: The list of arguments passed to ft_printf.
** specifier: The format specifier to handle.
** Return: The number of bytes written on success, -1 on failure.
*/

ssize_t	handle_format(va_list args, char specifier)
{
	ssize_t	result;

	if (specifier == 'c')
		result = ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		result = ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		result = ft_putptr(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		result = ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		result = ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		result = ft_puthex(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		result = ft_putchar('%');
	else
		result = ft_putchar(specifier);
	if (result == -1)
		return (-1);
	return (result);
}

/*
** A simplified implementation of printf that formats and writes data
** to the standard output based on a format string.
**
** Supported conversion specifications:
** - %c: Prints a single character.
** - %s: Prints a string.
** - %p: Prints a pointer in hexadecimal format.
** - %d: Prints a signed decimal integer.
** - %i: Prints a signed decimal integer.
** - %u: Prints an unsigned decimal integer.
** - %x: Prints an unsigned hexadecimal integer (lowercase).
** - %X: Prints an unsigned hexadecimal integer (uppercase).
** - %%: Prints a literal percent sign.
**
** format: The format string containing text and format specifiers.
** param ...: The variable arguments corresponding to the format specifiers.
** Return: The total number of bytes written on success, or -1 on failure.
*/

ssize_t	ft_printf(const char *format, ...)
{
	va_list	args;
	ssize_t	bytes_total;
	ssize_t	result;

	bytes_total = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && in_set(*(format + 1)))
		{
			format++;
			result = handle_format(args, *format);
		}
		else
			result = ft_putchar(*format);
		if (result == -1)
			return (va_end(args), -1);
		bytes_total += result;
		format++;
	}
	va_end(args);
	return (bytes_total);
}

ssize_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
