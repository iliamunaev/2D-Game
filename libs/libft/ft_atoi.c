/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:36:33 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:11:17 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts the initial portion of a string to an integer.
 *
 * This function skips leading whitespace, handles an optional '+' or '-' sign,
 * and accumulates numeric characters until encountering a non-digit or the end
 * of the string. The result is returned as an integer value.
 *
 * @param str The string to be converted.
 * @return int The converted integer, or 0 if no valid conversion could be
 * performed.
 */
int	ft_atoi(const char *str)
{
	int			sign;
	long long	num;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return ((int)(num * sign));
}
