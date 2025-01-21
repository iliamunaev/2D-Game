/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:00:26 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 20:55:53 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts an integer to a null-terminated string.
 *
 * This function allocates memory and returns a string representation of
 * the integer `n`. If the integer is negative, the resulting string includes
 * a leading '-' sign. Memory for the string is obtained using `malloc`
 * and must be freed by the caller.
 *
 * @param n The integer to convert to a string.
 * @return char* A pointer to the string representation of the integer, or
 *         NULL if memory allocation fails.
 */
static int	get_len(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*fill_str(char *str, unsigned int len, int n)
{
	char	*s;

	s = str;
	while (len > 0)
	{
		len--;
		s[len] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	sign = 1;
	len = get_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == -2147483648)
	{
		str[--len] = '8';
		n /= 10;
	}
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	fill_str(str, len, n);
	if (sign == -1)
		str[0] = '-';
	return (str);
}
