/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:13 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/04 18:26:13 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


t_map	*init_map(const char *map_file)
{
	t_map		*map;
	t_temp_map	*temp_map;

	temp_map = init_temp_map(map_file);
	if(!temp_map)
	{
		ft_putstr_fd("Error: init_map -> temp_map malloc failed.\n", 2);
		return (NULL);
	}
	if(!is_valid(temp_map))
	{
		free_temp_map(temp_map);
		ft_putstr_fd("Error: init_map -> map validation failed.\n", 2);
		return (NULL);
	}
	map = malloc(sizeof(t_map));
	if (!map)
	{
		free_temp_map(temp_map);
		ft_putstr_fd("Error: init_map -> map malloc failed.\n", 2);
		return (NULL);
	}
	if(fillup_map(map, temp_map) == EXIT_FAILURE)
	{
		free_temp_map(temp_map);
		free_map(map);
		ft_putstr_fd("Error: init_map -> fillup_map failed.\n", 2);
		return (NULL);
	}
	free_temp_map(temp_map);
	return (map);
}
