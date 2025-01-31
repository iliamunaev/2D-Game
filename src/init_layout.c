/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_layout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:51:36 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/31 17:26:02 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
	
int	init_layout(const char *map_file, t_temp_map *temp_map)
{
	int	fd;
	char	*line;
	
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: failed to read from fd\n", 2);
		return (INIT_ERROR);
	}
	 
	line = NULL;
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break;	
		
		if (temp_map->rows >= MAX_ROWS)
        {
            ft_putstr_fd("Error: temp_map too large\n", 2);
            //free_layout(temp_map);
            close(fd);
            return (INIT_ERROR);
        }
 
		temp_map->layout[temp_map->rows] = line;		
		
		if (!temp_map->layout[temp_map->rows])
		{
		//	free_layout(temp_map);
			return (INIT_ERROR);
		}
		temp_map->rows++;
	}

	temp_map->layout[temp_map->rows] = NULL;


	close(fd);
	
	return(INIT_SUCCESS);
}
