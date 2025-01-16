/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:35:18 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/11 11:14:19 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ft_strnstr() locates the first occurrence of the null-terminated
 * string 'little' in the string 'big', where not more than 'len' characters
 * are searched.
 * Return: 'big', if 'little' is an empty string;
 * NULL if 'little' occurs nowhere in 'big';
 * a pointer to the first character of the first occurrence of 'little'.
 */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (0);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (0);
}
