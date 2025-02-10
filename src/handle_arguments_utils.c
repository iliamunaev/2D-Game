/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:36:39 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/10 16:55:29 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Checks if the provided file path is not NULL.
 *
 * Ensures that the file path string is valid before proceeding
 * with further checks.
 *
 * @param map_file Pointer to the file path string.
 * @return true if the file path is valid, false otherwise.
 */
bool	check_path_not_null(const char *map_file)
{
	if (!map_file)
	{
		ft_putstr_fd("Error: File path is NULL.\n", 2);
		return (false);
	}
	return (true);
}

/**
 * @brief Validates the length of the file name.
 *
 * Ensures the file name is not empty and that its length falls within
 * a valid range (between 5 and 255 characters).
 *
 * @param file_name_len Length of the file name.
 * @return true if the file name length is valid, false otherwise.
 */
bool	check_filename_length(int file_name_len)
{
	if (file_name_len == 0)
	{
		ft_putstr_fd("Error: File name cannot be empty.\n", 2);
		return (false);
	}
	if (file_name_len < 5 || file_name_len > 255)
	{
		ft_putstr_fd("Error: File name is too short or too long.\n", 2);
		return (false);
	}
	return (true);
}

/**
 * @brief Checks if the file has a ".ber" extension.
 *
 * Verifies that the file name ends with ".ber", ensuring it meets
 * the expected format.
 *
 * @param map_file Pointer to the file path string.
 * @param file_name_len Length of the file name.
 * @return true if the file has a valid ".ber" extension, false otherwise.
 */
bool	check_extension_ber(const char *map_file, int file_name_len)
{
	if (!map_file || file_name_len < 4)
	{
		ft_putstr_fd("Error: File name is too short or NULL.\n", 2);
		return (false);
	}
	if (ft_strncmp(&map_file[file_name_len - 4], ".ber", 4) != 0)
	{
		ft_putstr_fd("Error: File must have a '.ber' extension.\n", 2);
		return (false);
	}
	return (true);
}

/**
 * @brief Checks for invalid characters in the file name.
 *
 * Ensures that the file name does not contain restricted characters
 * that are not allowed in file paths (such as \, :, *, ?, etc.).
 *
 * @param map_file Pointer to the file path string.
 * @param file_name_len Length of the file name.
 * @return true if the file name contains no invalid characters, false otherwise.
 */
bool	check_invalid_chars(const char *map_file, int file_name_len)
{
	static const char	*invalid_chars;
	int					i;

	invalid_chars = "\\:*?\"<>|";
	i = 0;
	while (i < file_name_len)
	{
		if (ft_strchr(invalid_chars, map_file[i]))
		{
			ft_putstr_fd("Error: File name contains invalid characters.\n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

/**
 * @brief Checks if the file exists in the filesystem.
 *
 * Uses the `access()` function to determine if the file exists.
 *
 * @param map_file Pointer to the file path string.
 * @return true if the file exists, false otherwise.
 */
bool	check_file_exists(const char *map_file)
{
	if ((access(map_file, F_OK) == -1) || (access(map_file, R_OK) == -1))
	{
		ft_putstr_fd("Error: File does not exist / no read permission.\n", 2);
		return (false);
	}
	return (true);
}
