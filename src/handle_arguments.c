/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:27:37 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/10 10:01:05 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Validates the given file path based on multiple criteria.
 *
 * Checks if the file path is non-null, has a valid length, contains 
 * a ".ber" extension, does not include invalid characters, and 
 * confirms that the file exists.
 *
 * @param map_file Pointer to the file path string.
 * @param filename_len Length of the file name.
 * @return true if the file path is valid, false otherwise.
 */
bool	is_path_valid(const char *map_file, int filename_len)
{
	if (!check_path_not_null(map_file))
		return (false);
	if (!check_filename_length(filename_len))
		return (false);
	if (!check_extension_ber(map_file, filename_len))
		return (false);
	if (!check_invalid_chars(map_file, filename_len))
		return (false);
	if (!check_file_exists(map_file))
		return (false);
	return (true);
}

/**
 * @brief Handles command-line arguments and validates the map file.
 *
 * Ensures that exactly one argument is provided, retrieves the map 
 * file name, and validates its path using `is_path_valid()`.
 *
 * @param ac Argument count.
 * @param av Argument vector.
 * @param map_file Pointer to store the validated map file path.
 * @return EXIT_SUCCESS if the map file is valid, EXIT_FAILURE otherwise.
 */
int	handle_arguments(int ac, char **av, const char **map_file)
{	
	int	filename_len;

	if (ac != 2)
	{
		ft_putstr_fd("Error: Please provide a map file.\n", 2);
		return (EXIT_FAILURE);
	}
	*map_file = av[1];
	filename_len = ft_strlen(*map_file);
	if (!is_path_valid(*map_file, filename_len))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
