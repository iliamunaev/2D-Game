/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_layout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:51:36 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/04 11:33:00 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
	
int	init_layout(const char *map_file, t_temp_map *temp_map)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: failed to read from fd\n", 2);
		return (INIT_ERROR);
	}
	else
		ft_putstr_fd("SUCCESS: init_layout() fd is opened\n", 2);

	 
	line = NULL;
	while(1)
	{
		line = get_next_line(fd);

		if(!line)
			break;	
		
		if (temp_map->rows >= MAX_ROWS)
        {
            ft_putstr_fd("Error: init_layout() temp_map too large\n", 2);
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
	temp_map->cols = ft_strlen(temp_map->layout[0]) - 1;


	close(fd);	
	return(INIT_SUCCESS);
}
