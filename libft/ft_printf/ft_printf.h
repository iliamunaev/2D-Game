/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:24:13 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/10 14:56:57 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

ssize_t	ft_printf(const char *format, ...);
ssize_t	handle_format(va_list args, char specifier);
int		in_set(char c);

// utils
ssize_t	ft_putchar(char c);
ssize_t	ft_putstr(char *str);
ssize_t	ft_putnbr(int n);
ssize_t	ft_putnbr_unsigned(unsigned int n);
ssize_t	ft_puthex(unsigned long num, char specifier);
ssize_t	ft_putptr(void *ptr);

#endif
