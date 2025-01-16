/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:54:47 by imunaev-          #+#    #+#             */
/*   Updated: 2024/11/07 17:43:33 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Applies the function ’f’ on each character of
 * the string passed as argument, passing its index
 * as first argument. Each character is passed by
 * address to ’f’ to be modified if necessary.
 * s: The string on which to iterate.
 * f: The function to apply to each character.
 * Return: None
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	if (s && f)
	{
		index = 0;
		while (s[index])
		{
			f(index, &s[index]);
			index++;
		}
	}
}
