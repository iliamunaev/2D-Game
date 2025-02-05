/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_temp_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:28:01 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/05 13:19:09 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	set_map_columns(t_temp_map *temp_map)
{
	int	len;

	if (!temp_map->layout[0] || ft_strlen(temp_map->layout[0]) == 0)
	{
		ft_putstr_fd("Error: first row is empty.\n", 2);
		return (EXIT_FAILURE);
	}
	len = ft_strlen(temp_map->layout[0]);
	temp_map->cols = len - 1;
	return (EXIT_SUCCESS);
}

static int	read_map_lines(int fd, t_temp_map *temp_map)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (temp_map->rows >= MAX_ROWS)
		{
			ft_putstr_fd("Error: map has too many rows.\n", 2);
			free(line);
			return (-1);
		}
		temp_map->layout[temp_map->rows] = line;
		temp_map->rows++;
	}
	temp_map->layout[temp_map->rows] = NULL;
	if (temp_map->rows == 0)
	{
		ft_putstr_fd("Error: map file is empty.\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	init_layout(const char *map_file, t_temp_map *temp_map)
{
	int	fd;

	fd = open_map_file(map_file);
	if (fd < 0)
		return (EXIT_FAILURE);
	if (read_map_lines(fd, temp_map) == -1)
	{
		close(fd);
		while (--temp_map->rows >= 0)
			free(temp_map->layout[temp_map->rows]);
		free(temp_map->layout);
		temp_map->layout = NULL;
		return (EXIT_FAILURE);
	}
	close(fd);
	if (set_map_columns(temp_map) == EXIT_FAILURE)
	{
		while (--temp_map->rows >= 0)
			free(temp_map->layout[temp_map->rows]);
		free(temp_map->layout);
		temp_map->layout = NULL;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	fillup_temp_map(t_temp_map *temp_map, const char *map_file)
{
	temp_map->rows = 0;
	temp_map->cols = 0;
	temp_map->collects = 0;
	temp_map->exit = 0;
	temp_map->layout = malloc(MAX_ROWS * sizeof(char *));
	if (!temp_map->layout)
	{
		ft_putstr_fd("Error: temp_map layout malloc failed.\n", 2);
		return (EXIT_FAILURE);
	}
	if (init_layout(map_file, temp_map) == EXIT_FAILURE)
	{
		ft_putstr_fd("Error: fillup_temp_map -> init_layout failed.\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

t_temp_map	*init_temp_map(const char *map_file)
{
	t_temp_map	*temp_map;

	temp_map = malloc(sizeof(t_temp_map));
	if (!temp_map)
	{
		ft_putstr_fd("Error: init_temp_map -> temp_map  malloc failed.\n", 2);
		return (NULL);
	}
	if (fillup_temp_map(temp_map, map_file) == EXIT_FAILURE)
	{
		free(temp_map);
		return (NULL);
	}
	trim_2d_array(temp_map->layout);
	return (temp_map);
}
