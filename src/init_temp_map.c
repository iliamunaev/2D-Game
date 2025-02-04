/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_temp_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:48:57 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/04 22:29:24 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	trim_2d_array(char **arr)
{
	int i;
	int	len;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		len = ft_strlen(arr[i]);
		if (len > 0 && arr[i][len - 1] == '\n')
			arr[i][len - 1] = '\0';
		i++;
	}
}
int	open_map_file(const char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("Error: failed to open map file.\n", 2);
	return (fd);
}

int	set_map_columns(t_temp_map *temp_map)
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

int read_map_lines(int fd, t_temp_map *temp_map)
{
    char	*line;

    while ((line = get_next_line(fd)) != NULL)
    {
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

int init_layout(const char *map_file, t_temp_map *temp_map)
{
    int fd = open_map_file(map_file);
    if (fd < 0)
        return (EXIT_FAILURE);

    if (read_map_lines(fd, temp_map) == EXIT_FAILURE)
    {
        close(fd);
        while (--temp_map->rows >= 0)
        {
            free(temp_map->layout[temp_map->rows]);
        }
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

int fillup_temp_map(t_temp_map *temp_map, const char *map_file)
{
	temp_map->rows = 0;
	temp_map->cols = 0;
	temp_map->collects = 0;
	temp_map->exit = 0;
	temp_map->layout = malloc(MAX_ROWS * sizeof(char *));
	if(!temp_map->layout)
	{
		ft_putstr_fd("Error: fillup_temp_map -> temp_map layout malloc failed.\n", 2);
		return (EXIT_FAILURE);
	}
	if(init_layout(map_file, temp_map) == EXIT_FAILURE)
	{
		ft_putstr_fd("Error: fillup_temp_map -> init_layout failed.\n", 2);
		return (EXIT_FAILURE);
	}
	return(EXIT_SUCCESS);
}

t_temp_map	*init_temp_map(const char *map_file)
{
	t_temp_map	*temp_map;

	temp_map = malloc(sizeof(t_temp_map));
	if(!temp_map)
	{
		ft_putstr_fd("Error: init_temp_map -> temp_map  malloc failed.\n", 2);
		return (NULL);
	}
	if(fillup_temp_map(temp_map, map_file) == EXIT_FAILURE)
	{
		free(temp_map);
		return (NULL);
	}
	trim_2d_array(temp_map->layout);
	return (temp_map);
}


