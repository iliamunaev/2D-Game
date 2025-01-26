/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:13 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/26 13:36:14 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_layout(char *map_file, t_map *map)
{
	int	fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: failed to read from fd\n", 2);
		return (EXIT_FAILURE);
	}

	while(map->rows <= MAX_COLUMNS)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		if(line && (map->rows == MAX_COLUMNS))
		{
			ft_putstr_fd("Error: map is too big\n", 2);
			return (EXIT_FAILURE);
		}

		map->layout[map->rows] = ft_strdup(line);
		if(!map->layout[map->rows])
		{
			map->rows--;
			while(map->rows <= 0)
			{
				free(map->layout[map->rows]);
				map->rows--;
			}
			free(map->layout);
		}
		map->rows++;
	}
	map->layout[map->rows] = NULL;
	close(fd);

	if(validate_layout(map) == EXIT_FAILURE)
	{
		ft_putstr_fd("Error: _____\n", 2);
		return (EXIT_FAILURE);
	}
	return(EXIT_SUCCESS);
}


int	init_map(char *map_file, t_map *map)
{
	map->columns = 0;
	map->rows = 0;
	map->collectibles = 0;
	map->walls = 0;
	map->player = 0;
	map->exit = 0;
	map->layout = malloc((MAX_ROWS + 1) * sizeof(char *));
	if(!map->layout)
	{
		ft_putstr_fd("Error: failed to read from fd\n", 2);
		return (EXIT_FAILURE);
	}
	if(fill_layout(map_file, map) == EXIT_FAILURE)
	{
		ft_putstr_fd("Error: _____\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}



t_map	*load_map(char *map_file)
{
	t_map	*map;

	if(is_valid_file(map_file) == false)
	{
		ft_putstr_fd("Error: invalide file\n", 2);
		return (NULL);
	}

	map = malloc(sizeof(t_map));
	if (!map)
	{
		exit_with_error("Failed to allocate memory for map");
		return (NULL);
	}

	if(init_map(map_file, map) == EXIT_FAILURE)
	{
		free_map(map); // check all
		return (NULL);
	}
	return (map);
}
