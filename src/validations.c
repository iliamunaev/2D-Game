/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:32 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/26 13:36:33 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_valid_file(char *map_file)
{
	const char	*extension;
	int	file_name_len;

	if (!map_file)
		return (false);
	file_name_len = ft_strlen(map_file);
	if (file_name_len <= 4)
		return (false);
	extension = ft_strrchr(map_file, '.');
	if (!extension)
		return (false);
	if(ft_strcmp(extension, ".ber") != 0)
		return (false);
	if (extension == map_file)
		return (false);
	return (true);
}

int	validate_layout(t_map *map)
{
	int	i;
	int	j;

	if(map->rows < 3)
	{
		//free
		return(EXIT_FAILURE);
	}

	i = 0;
	map->columns = ft_strlen(map->layout[0]);
	while(map->layout[i])
	{
		if(map->columns != ft_strlen(map->layout[i]))
		{
			//free
			return (EXIT_FAILURE);
		}

		map->walls = ft_count_char(map->layout[i], '1');
		map->player = ft_count_char(map->layout[i], 'P');
		map->exit = ft_count_char(map->layout[i], 'E');
		map->collectibles = ft_count_char(map->layout[i], 'C');
		i++;
	}

	if(map->player != 1 || map->exit != 1 || map->collectibles < 1)
	{
		//free
		return(EXIT_FAILURE);
	}
	// FROM HERE - VALIDATE str1 and str last + first and last char

	return(EXIT_SUCCESS);
}
