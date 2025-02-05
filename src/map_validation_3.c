/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:19:48 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/05 13:30:40 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_start(t_temp_map *temp_map, t_start *start)
{
	int	y;
	int	x;

	y = 0;
	while (temp_map->layout[y])
	{
		x = 0;
		while (temp_map->layout[y][x])
		{
			if (temp_map->layout[y][x] == PLAYER)
			{
				start->row = y;
				start->col = x;
				return (EXIT_SUCCESS);
			}
			x++;
		}
		y++;
	}
	return (EXIT_FAILURE);
}

static bool	is_avoid_char(t_temp_map *temp_map, int y, int x)
{
	if (y < 0 || y >= temp_map->rows || x < 0 || x >= temp_map->cols)
		return (true);
	if (temp_map->layout[y][x] == WALL
		|| temp_map->layout[y][x] == 'L'
		|| temp_map->layout[y][x] == 'X'
		|| temp_map->layout[y][x] == 'O'
		|| temp_map->layout[y][x] == 'A')
		return (true);
	return (false);
}

static void	fill_check(t_temp_map *temp_map, int y, int x)
{
	char	**map;

	map = temp_map->layout;
	if (is_avoid_char(temp_map, y, x))
		return ;
	if (map[y][x] == FLOOR)
		map[y][x] = 'L';
	if (map[y][x] == EXIT)
	{
		map[y][x] = 'X';
		temp_map->exit -= 1;
	}
	if (map[y][x] == COLLECTIBLE)
	{
		map[y][x] = 'O';
		temp_map->collects -= 1;
	}
	if (map[y][x] == PLAYER)
		map[y][x] = 'A';
	fill_check(temp_map, y + 1, x);
	fill_check(temp_map, y - 1, x);
	fill_check(temp_map, y, x + 1);
	fill_check(temp_map, y, x - 1);
}

static bool	is_add_validate(t_temp_map *temp_map, t_start *start)
{
	int	collects_to_check;
	int	exits_to_check;
	int	player_to_check;

	collects_to_check = ft_parse_char_2d_arr(temp_map->layout, COLLECTIBLE);
	exits_to_check = ft_parse_char_2d_arr(temp_map->layout, EXIT);
	player_to_check = ft_parse_char_2d_arr(temp_map->layout, PLAYER);
	if (collects_to_check < 1 || exits_to_check != 1 || player_to_check != 1)
	{
		ft_putstr_fd("Error: Wrong nums of collects/exits/players found.\n", 2);
		return (false);
	}
	temp_map->collects = collects_to_check;
	temp_map->exit = exits_to_check;
	fill_check(temp_map, start->row, start->col);
	if (temp_map->collects != 0 || temp_map->exit != 0)
	{
		ft_putstr_fd("Error: Not all collectibles or exit are reachable.\n", 2);
		return (false);
	}
	revert_map(temp_map);
	return (true);
}

bool	additional_validation(t_temp_map *temp_map)
{
	t_start	start;

	if (get_start(temp_map, &start) == EXIT_FAILURE)
		return (false);
	if (!is_add_validate(temp_map, &start))
		return (false);
	return (true);
}
