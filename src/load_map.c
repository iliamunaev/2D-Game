/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:13 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/26 20:22:01 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_layout(char *map_file, t_map *map, t_monitor *monitor)
{
	int	fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: failed to read from fd\n", 2);
		return (INIT_ERROR);
	}

	while(map->rows <= MAX_COLUMNS)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		if(line && (map->rows == MAX_COLUMNS))
		{
			ft_putstr_fd("Error: map is too big\n", 2);
			return (INIT_ERROR);
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

	if(!is_validate_layout(map, monitor))
	{
		ft_putstr_fd("Error: map validation failure\n", 2);
		return (INIT_ERROR);
	}
	return(INIT_SUCCESS);
}

int	init_map(char *map_file, t_map *map, t_monitor *monitor)
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
		clean_up_game(NULL, map, "Error: memory allocation for map.layout failure\n", NULL);
		return (INIT_ERROR);
	}
	if(fill_layout(map_file, map, monitor) == INIT_ERROR)
	{
		clean_up_game(NULL, map, "Error: map.layout filling failure\n", NULL);
		return (INIT_ERROR);
	}
	return (INIT_SUCCESS);
}

t_map	*load_map(const char *file_path, t_monitor *monitor)
{
	t_map	*map;

	if(!is_valid_file(file_path))
	{
		ft_putstr_fd("Error: invalide map file\n", 2);
		return (NULL);
	}
	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_putstr_fd("Error: memory allocation for map failure\n", 2);
		return (NULL);
	}
	if(init_map(file_path, map, monitor) == INIT_ERROR)
		return (NULL);
	return (map);
}
