/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_temp_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:48:57 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/04 16:35:24 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	trim_2d_array(char **arr)
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

int	init_layout(const char *map_file, t_temp_map *temp_map)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: failed to read from fd\n", 2);
		return (EXIT_FAILURE);
	}
	line = NULL;
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break ;
		if (temp_map->rows >= MAX_ROWS)
        {
			while(--temp_map->rows >= 0)
			{
				free(temp_map->layout[temp_map->rows]);
			}
			free(temp_map->layout);
			temp_map->layout = NULL;
            ft_putstr_fd("Error: init_layout-> map is too large\n", 2);
            close(fd);
            return (EXIT_FAILURE);
        }		
		temp_map->layout[temp_map->rows] = line;		
		if (!temp_map->layout[temp_map->rows])
		{
			while(--temp_map->rows >= 0)
			{
				free(temp_map->layout[temp_map->rows]);
			}
			free(temp_map->layout);
			temp_map->layout = NULL;
			return (EXIT_FAILURE);
		}
		temp_map->rows++;
	}
	temp_map->layout[temp_map->rows] = NULL;
	temp_map->cols = ft_strlen(temp_map->layout[0]) - 1;
	close(fd);	
	return(EXIT_SUCCESS);
}

static int fillup_temp_map(t_temp_map *temp_map, const char *map_file)
{
	temp_map->rows = 0;
	temp_map->cols = 0;	
	temp_map->layout = malloc(MAX_ROWS * sizeof(char *));
	if(!temp_map->layout)
	{
		ft_putstr_fd("Error: fillup_temp_map -> temp_map layout malloc failed\n", 2);
		return (EXIT_FAILURE);
	}
	if(init_layout(map_file, temp_map) == EXIT_FAILURE)
	{
		ft_putstr_fd("ERROR: fillup_temp_map(): init_layout() failed\n", 2);
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
		ft_putstr_fd("Error: init_temp_map -> temp_map  malloc failed\n", 2);
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
