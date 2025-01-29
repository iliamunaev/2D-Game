/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:13 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/27 18:16:29 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_layout(t_map *map)
{
    while (map->rows > 0)
    {
        map->rows--;
        free(map->layout[map->rows]);
    }
    free(map->layout);
}


int	fill_layout(const char *map_file, t_map *map, t_monitor *monitor)
{
	int	fd;
	char	*line;
	(void)monitor; // test
	
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: failed to read from fd\n", 2);
		return (INIT_ERROR);
	}
	 
	
	line = NULL;
	while(1)
	{
		line = get_next_line(fd); // the function output tested
		if(!line)
			break;	
		printf("get_next_line: %s", line); // test
		
		if (map->rows >= (monitor->height / TILE_SIZE))
        {
            ft_putstr_fd("Error: map too large\n", 2);
            free_layout(map);
            close(fd);
            return (INIT_ERROR);
        }
 
		map->layout[map->rows] = line;		
		printf("map->layout[map->rows]: %s", map->layout[map->rows]); // test
		
		if (!map->layout[map->rows])
		{
			free_layout(map);
			return (INIT_ERROR);
		}
		map->rows++;
		printf("in loop map->rows index: %d\n", map->rows); // test	
	}
	printf("map->rows index: %d\n", map->rows); // test		

	map->layout[map->rows] = NULL;
	printf("map->layout[map->rows]: %s", map->layout[map->rows]); // test


	close(fd);
	
	// uncomment for production
	// if(!is_validate_layout(map, monitor))
	// {
	// 	ft_putstr_fd("Error: map validation failure\n", 2);
	// 	return (INIT_ERROR);
	// }
	return(INIT_SUCCESS);
}

int	init_map(const char *map_file, t_map *map, t_monitor *monitor)
{

	map->columns = 0;
	map->rows = 0;
	map->collectibles = 0;
	map->walls = 0;
	map->player = 0;
	map->exit = 0;
	map->layout = malloc(((monitor->height / TILE_SIZE) + 1) * sizeof(char *));
	if(!map->layout)
	{
		printf("init_map(): ERROR mem alloc for layout\n");
		return (INIT_ERROR);
	}

	if(fill_layout(map_file, map, monitor) == INIT_ERROR)
	{
		printf("fill_layout(): ERROR \n");
		return (INIT_ERROR);
	}
	else 
		printf("here\n"); // test		


	return (INIT_SUCCESS);
}

t_map	*load_map(const char *file_path, t_monitor *monitor)
{
	t_map	*map;

	// if(!is_valid_file(file_path))
	// {
	// 	ft_putstr_fd("Error: invalide map file\n", 2);
	// 	return (NULL);
	// }
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
