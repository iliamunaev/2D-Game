/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_temp_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:48:57 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/01 16:25:58 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	trim_2d_array(char **arr)
{
	int i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
    {
		size_t len = ft_strlen(arr[i]);
		if (len > 0 && arr[i][len - 1] == '\n')
			arr[i][len - 1] = '\0';
		i++;
    }
}

static int fillup_temp_map(t_temp_map *temp_map, const char *map_file)
{
	temp_map->rows = 0;
	temp_map->cols = 0;

	
	temp_map->layout = malloc(sizeof(char *) * MAX_ROWS);
	if(!temp_map->layout)
	{
		ft_putstr_fd("ERROR: fillup_temp_map(): temp_map->layout malloc failed\n", 2);
		return (INIT_ERROR);
	}
	else 
		ft_putstr_fd("SUCCESS: fillup_temp_map(): temp_map->layout malloc -> ok\n", 2);


	if(init_layout(map_file, temp_map) == INIT_ERROR)
	{
		ft_putstr_fd("ERROR: fillup_temp_map(): init_layout() failed\n", 2);
		return (INIT_ERROR);
	}
	else 
		ft_putstr_fd("SUCCESS: fillup_temp_map(): init_layout() -> ok\n", 2);
			
	return(INIT_SUCCESS);
}


t_temp_map	*init_temp_map(const char *map_file)
{
	t_temp_map	*temp_map;

	temp_map = malloc(sizeof(t_temp_map));
	if(!temp_map)
	{
		ft_putstr_fd("ERROR: init_temp_map(): temp_map memory allocation failed\n", 2);
		return (NULL);
	}
	else 
		ft_putstr_fd("SUCCESS: init_temp_map(): temp_map memory allocation\n", 2);  // test


		
	if(fillup_temp_map(temp_map, map_file) == INIT_ERROR)	
	{
		ft_putstr_fd("ERROR: init_temp_map(): fillup_temp_map() failed\n", 2);
		return (NULL);
	}
	else 
		ft_putstr_fd("SUCCESS: init_temp_map(): fillup_temp_map() -> ok\n", 2);  // test
		
	trim_2d_array(temp_map->layout);
	return (temp_map);	
}
