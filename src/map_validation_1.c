/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:55:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/05 12:53:43 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_valid(t_temp_map *temp_map)
{
	if (!is_walls(temp_map)
		|| !is_in_max_columns(temp_map)
		|| !is_rectangular(temp_map)
		|| !is_valid_chars(temp_map)
		|| !additional_validation(temp_map))
	{
		free_temp_map(temp_map);
		return (false);
	}
	return (true);
}
