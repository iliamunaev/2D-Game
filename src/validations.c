/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:32 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/26 20:51:34 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_valid_file(const char *map_file)
{
	const char	*extension;
	int	file_name_len;

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

static bool	is_validate_sprites(t_map *map)
{
	int i;

	i = 0;
	while(map->layout[i])
	{
		map->player = ft_count_char(map->layout[i], 'P');
		map->exit = ft_count_char(map->layout[i], 'E');
		map->collectibles = ft_count_char(map->layout[i], 'C');
		i++;
	}
	if(map->player != 1 || map->exit != 1 || map->collectibles < 1)
	{
		clean_up_game(NULL, map, "Error: no player/exit/collectibles\n", NULL);
		return(false);
	}
	return(true);
}

static bool	is_validate_walls(t_map *map)
{
	int	first_row;
	int	last_row;
	int	first_char;
	int	last_char;
	char	wall;

	first_row = 0;
	last_row = ft_strlen(map->layout) - 1;
	first_char = 0;
	last_char = ft_strlen(map->layout[first_row]) - 1;
	wall = 'C';

	ft_confirm_charstr(map->layout[first_row], wall);
	ft_confirm_charstr(map->layout[last_row], wall);

	while(first_row + 1 <= last_row - 1)
	{
		if(ft_strchr(map->layout[first_row + 1], wall) != 0 || ft_strrchr(map->layout[first_row + 1], wall) != last_char)
		{
			clean_up_game(NULL, map, "Error: map walls failure 3\n", NULL);
			return(false);
		}
		first_row++;
	}
	return(true);
}

static bool	is_validate_columns(t_map *map, t_monitor *monitor)
{
	int	i;
	int	columns;

	i = 0;

	columns = ft_strlen(map->layout[i]);

	map->columns = columns;

	while(map->layout[i])
	{
		columns = ft_strlen(map->layout[i]);
		if(columns < 3)
		{
			clean_up_game(NULL, map, "Error: map columns less than 3\n", NULL);
			return (false);
		}
		if(columns * TILE_SIZE > *monitor->width)
		{
			clean_up_game(NULL, map, "Error: monitor width is not sutable\n", NULL);
			return (false);
		}
		if(map->columns != columns)
		{
			clean_up_game(NULL, map, "Error: map is not rectangular\n", NULL);
			return (false);
		}
		i++;
	}
	return(true);
}

static bool	is_validate_rows(t_map *map, t_monitor *monitor)
{
	if(map->rows < 4)
	{
		clean_up_game(NULL, map, "Error: map rows less than 3\n", NULL);
		return(false);
	}
	if(map->rows  * TILE_SIZE > *monitor->height)
	{
		clean_up_game(NULL, map, "Error: monitor height is not sutable\n", NULL);
		return (false);
	}
	return(true);
}

bool	is_validate_layout(t_map *map, t_monitor *monitor)
{
	if(!is_validate_rows(map, monitor))
		return (false);

	if(!is_validate_columns(map, monitor))
		return (false);

	if(!is_validate_walls(map))
		return (false);

	if(!is_validate_sprites(map))
		return (false);
	return(true);
}
