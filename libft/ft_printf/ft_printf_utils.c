/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:07:18 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/08 15:26:24 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putstr(char *str)
{
	ssize_t	count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

ssize_t	ft_putptr(void *ptr)
{
	ssize_t			count;
	unsigned long	address;

	address = (unsigned long)ptr;
	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_puthex(address, 'x');
	return (count);
}

ssize_t	ft_puthex(unsigned long num, char specifier)
{
	ssize_t	count;
	char	*hex_digits;

	count = 0;
	if (specifier == 'x')
		hex_digits = "0123456789abcdef";
	else if (specifier == 'X')
		hex_digits = "0123456789ABCDEF";
	else
		return (0);
	if (num >= 16)
		count += ft_puthex(num / 16, specifier);
	count += ft_putchar(hex_digits[num % 16]);
	return (count);
}

ssize_t	ft_putnbr_unsigned(unsigned int n)
{
	ssize_t	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

ssize_t	ft_putnbr(int n)
{
	ssize_t	count;
	long	num;

	count = 0;
	num = n;
	if (num < 0)
	{
		count += ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
		count += ft_putnbr(num / 10);
	count += ft_putchar((num % 10) + '0');
	return (count);
}
