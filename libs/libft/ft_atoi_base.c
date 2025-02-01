/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:21:45 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/30 23:51:37 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Checks if a character is a whitespace character.
 *
 * This function checks if the given character is a space, newline, tab,
 * vertical tab, form feed, or carriage return.
 *
 * @param c The character to check.
 * @return true if the character is a whitespace, false otherwise.
 */
static int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r');
}

/**
 * @brief Checks if a number is valid within a given base.
 *
 * This function verifies if the number `num` is within the valid
 * range `[0, base-1]`.
 *
 * @param num The number to check.
 * @param base The numerical base.
 * @return true if the number is valid for the base, false otherwise.
 */
static int	is_valid(int num, int base)
{
	return (num >= 0 && num < base);
}

/**
 * @brief Converts a character to its numerical value in a given base.
 *
 * This function converts a digit or an alphanumeric character into its
 * corresponding numerical value based on the provided base.
 *
 * @param c The character to convert.
 * @return The numerical value of the character, or -1 if it is not valid.
 */
static int	get_value(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else if (ft_is_lower_alpha(c))
		return ((c - 'a') + 10);
	else if (ft_is_upper_alpha(c))
		return ((c - 'A') + 10);
	return (-1);
}

/**
 * @brief Parses the number in the given base and converts it to an integer.
 *
 * This function processes the valid characters of a number string, converting
 * it to an integer based on the provided numerical base.
 *
 * @param s The input string containing the number.
 * @param base The numerical base (between 2 and 16).
 * @return The converted number.
 */
static long	parse_number_base(const char *s, int base)
{
	int		value;
	long	num;

	num = 0;
	while (*s)
	{
		value = get_value(*s);
		if (!is_valid(value, base))
			break ;
		num = num * base + value;
		s++;
	}
	return (num);
}

/**
 * @brief Converts a string representation of a number in
 * a given base to an integer.
 *
 * This function parses a string `s`, interpreting it as a number in
 * the specified numerical base (between 2 and 16), and returns
 * the corresponding integer.
 *
 * @param s The input string representing a number.
 * @param base The numerical base of the input string (must be between 2 and 16).
 * @return The integer value of the string in the given base, or 0 on failure.
 */
int	ft_atoi_base(const char *s, int base)
{
	int		sign;
	long	num;

	sign = 1;
	if (!s || base < 2 || base > 16)
		return (0);
	while (is_space(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	num = parse_number_base(s, base);
	return ((int)(num * sign));
}
