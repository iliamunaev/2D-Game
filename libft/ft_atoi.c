/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:36:33 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/17 21:52:29 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The function converts the initial portion of the string
** pointed to by 'str' to 'int'.
** Return: the converted value or '0' on error.
*/

int	ft_atoi(const char *str)
{
	int			sign;
	long long	num;

	num = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\f' || *str == '\r'
		|| *str == '\t' || *str == '\v')
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return ((int)(num * sign));
}
