/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:54:47 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/18 12:36:10 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Iterates through a string and applies a function to each character.
 *
 * This function applies the given function `f` to each character of
 * the string `s`.
 * The index of the character is passed as the first argument to `f`,
 * and the character's
 * address is passed as the second argument, allowing modification of
 * the character if needed.
 *
 * @param s The string to iterate through. If NULL, the function does nothing.
 * @param f The function to apply to each character. It takes the character
 *          index and a pointer to the character as arguments.
 * @return void This function does not return a value.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
