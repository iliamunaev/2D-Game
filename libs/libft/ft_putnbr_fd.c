/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:22:42 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:21:51 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs an integer to a specified file descriptor.
 *
 * This function writes the integer `n` to the file descriptor `fd`.
 * If the integer is negative, a '-' sign is output first, followed
 * by the absolute value of the number. The function handles the special
 * case of the smallest possible integer (-2147483648) to ensure correct output.
 *
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 * @return void This function does not return a value.
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
}
