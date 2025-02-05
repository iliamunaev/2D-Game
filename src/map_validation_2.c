/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:18:52 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/05 11:20:08 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_left_n_right_walls(t_temp_map *temp_map)
{
	int	i;

	i = 0;
	while (temp_map->layout[i])
	{
		if (temp_map->layout[i][0] != '1')
		{
			ft_putstr_fd("Error: Left wall not closed.\n", 2);
			return (false);
		}
		if (temp_map->layout[i][temp_map->cols - 1] != '1')
		{
			ft_putstr_fd("Error: Right wall not closed.\n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	is_walls(t_temp_map *temp_map)
{
	if (!ft_is_char_arr_solid(temp_map->layout[0], WALL))
	{
		ft_putstr_fd("Error: Top wall not closed.\n", 2);
		return (false);
	}
	if (!ft_is_char_arr_solid(temp_map->layout[temp_map->rows - 1], WALL))
	{
		ft_putstr_fd("Error: Bottom wall not closed.\n", 2);
		return (false);
	}
	if (!is_left_n_right_walls(temp_map))
		return (false);
	return (true);
}

bool	is_rectangular(t_temp_map *temp_map)
{
	int	i;
	int	len_sample;
	int	curr_len;

	len_sample = ft_strlen(temp_map->layout[0]);
	i = 1;
	while (temp_map->layout[i])
	{
		curr_len = ft_strlen(temp_map->layout[i]);
		if (curr_len != len_sample)
		{
			ft_putstr_fd("Error: The map is not rectangular.\n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	is_in_max_columns(t_temp_map *temp_map)
{
	if (temp_map->cols > MAX_COLUMNS)
	{
		ft_putstr_fd("Error: Number of columns exceeds max.\n", 2);
		return (false);
	}
	return (true);
}

bool	is_valid_chars(t_temp_map *temp_map)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	arr = temp_map->layout;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (!(arr[i][j] == FLOOR || arr[i][j] == WALL
				|| arr[i][j] == PLAYER || arr[i][j] == EXIT
				|| arr[i][j] == COLLECTIBLE))
			{
				ft_putstr_fd("Error: The map contains an invalid char.\n", 2);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
