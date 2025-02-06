/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:27:37 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/06 08:56:47 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
