/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:36:39 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/05 14:36:52 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_path_not_null(const char *map_file)
{
	if (!map_file)
	{
		ft_putstr_fd("Error: File path is NULL.\n", 2);
		return (false);
	}
	return (true);
}

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

bool	check_extension_ber(const char *map_file, int file_name_len)
{
	if (ft_strncmp(&map_file[file_name_len - 4], ".ber", 4) != 0)
	{
		ft_putstr_fd("Error: File must have a '.ber' extension.\n", 2);
		return (false);
	}
	return (true);
}

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

bool	check_file_exists(const char *map_file)
{
	if (access(map_file, F_OK) == -1)
	{
		ft_putstr_fd("Error: File does not exist.\n", 2);
		return (false);
	}
	return (true);
}
