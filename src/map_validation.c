/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:55:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/05 08:32:05 by imunaev-         ###   ########.fr       */
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

int	get_start(t_temp_map *temp_map, t_start *start)
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
	free(start);
	return (EXIT_FAILURE);
}

void	revert_map(t_temp_map *temp_map)
{

	int y = 0;
	while (y < temp_map->rows)
	{
		int x = 0;
		while (x < temp_map->cols)
		{

			char c = temp_map->layout[y][x];
			if (c == 'L')
				temp_map->layout[y][x] = FLOOR;
			else if (c == 'X')
			{
				temp_map->layout[y][x] = EXIT;
				temp_map->exit++;
			}
			else if (c == 'O')
			{
				temp_map->layout[y][x] = COLLECTIBLE;
				temp_map->collects++;
			}
			else if (c == 'A')
				temp_map->layout[y][x] = PLAYER;
			x++;
		}
		y++;
	}
}

void fill_check(t_temp_map *temp_map, int y, int x)
{
	char	**map;

	map = temp_map->layout;
	if (y < 0 || y >= temp_map->rows || x < 0 || x >= temp_map->cols)
		return ;
	if (map[y][x] == WALL || map[y][x] == 'L' || map[y][x] == 'X' || map[y][x] == 'O'|| map[y][x] == 'A')
		return ;
	if(map[y][x] == FLOOR)
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

bool	is_add_validate(t_temp_map *temp_map, t_start *start)
{
	int	collects_to_check;
	int	exits_to_check;

	collects_to_check = ft_parse_char_2d_arr(temp_map->layout, COLLECTIBLE);
	exits_to_check = ft_parse_char_2d_arr(temp_map->layout, EXIT);

	printf("collects_to_check: %d\n", collects_to_check);
	printf("exits_to_check: %d\n", exits_to_check);

	if (collects_to_check < 1)
	{
		ft_putstr_fd("Error: No collectible(s) found.\n", 2);
		free(start);
		return (false);
	}
	if (exits_to_check != 1)
	{
		ft_putstr_fd("Error: No exit or more than one exit found.\n", 2);
		free(start);
		return (false);
	}
	temp_map->collects = collects_to_check;
	temp_map->exit= exits_to_check;

	fill_check(temp_map, start->row, start->col);

	printf("temp_map->collects: %d\n", temp_map->collects );
	printf("temp_map->exit: %d\n", temp_map->exit );


	if (temp_map->collects != 0 || temp_map->exit != 0)
	{
		ft_putstr_fd("Error: Not all collectibles or exit are reachable.\n", 2);
		free(start);
		return (false);
	}
	revert_map(temp_map);

	printf("rev temp_map->collects: %d\n", temp_map->collects );
	printf("rev temp_map->exit: %d\n", temp_map->exit );

	free(start);

	return (true);
}

bool	additional_validation(t_temp_map *temp_map)
{
	t_start	*start;

	start = malloc(sizeof(t_start));
	if(!start)
	{
		ft_putstr_fd("Error: is_valid -> t_start malloc failed.\n",  2);
		return (false);
	}
	if(get_start(temp_map, start) == EXIT_FAILURE)
	{
		return (false);
	}
	if(!is_add_validate(temp_map, start))
	{
		return (false);
	}
	return (true);
}

bool	is_valid(t_temp_map *temp_map)
{
	if (!is_walls(temp_map))
		return (false);
	if (!is_in_max_columns(temp_map))
		return (false);
	if (!is_rectangular(temp_map))
		return (false);
	if (!is_valid_chars(temp_map))
		return (false);
	if (!additional_validation(temp_map))
		return (false);

	return (true);
}
