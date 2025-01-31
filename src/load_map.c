/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:13 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/31 17:19:38 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


t_map	*load_map(const char *map_file)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{		
		ft_putstr_fd("ERROR: load_map() map mem alloc failed\n", 2);
		return(NULL);
	}
	else 
		ft_putstr_fd("SUCCESS: load_map() map mem alloc\n", 2);
	
	
	if(init_map(map_file, map) == INIT_ERROR)
	{		
		ft_putstr_fd("ERROR: load_map() init_map failed\n", 2);
		return(NULL);
	}
	else 
		ft_putstr_fd("SUCCESS: load_map() init_map\n", 2);
		
	return (map);
}
