/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:18:52 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/10 10:18:24 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Checks if the left and right walls of the map are properly enclosed.
 *
 * Iterates through each row of the map and ensures that the first and last 
 * column contain wall characters ('1'). Prints an error message if
 * a wall is missing.
 *
 * @param temp_map Pointer to the temporary map structure.
 * @return true if the left and right walls are enclosed, false otherwise.
 */
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

/**
 * @brief Checks if the map is enclosed by walls on all sides.
 *
 * Ensures that the top and bottom rows are entirely filled with walls ('1') 
 * and that the left and right walls are properly enclosed.
 *
 * @param temp_map Pointer to the temporary map structure.
 * @return true if the map is enclosed by walls, false otherwise.
 */
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

/**
 * @brief Checks if the map has a rectangular shape.
 *
 * Compares the length of each row to ensure they are all the same, 
 * verifying the map is rectangular.
 *
 * @param temp_map Pointer to the temporary map structure.
 * @return true if the map is rectangular, false otherwise.
 */
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

/**
 * @brief Ensures that the map does not exceed the maximum allowed columns.
 *
 * Checks if the number of columns in the map exceeds the defined 
 * `MAX_COLUMNS` limit.
 *
 * @param temp_map Pointer to the temporary map structure.
 * @return true if the column count is within limits, false otherwise.
 */
bool	is_in_max_columns(t_temp_map *temp_map)
{
	if (temp_map->cols > MAX_COLUMNS)
	{
		ft_putstr_fd("Error: Number of columns exceeds max.\n", 2);
		return (false);
	}
	return (true);
}

/**
 * @brief Validates that the map contains only allowed characters.
 *
 * Iterates through the map to check that each character is a valid 
 * game element (floor, wall, player, exit, collectible). Prints an 
 * error message if an invalid character is found.
 *
 * @param temp_map Pointer to the temporary map structure.
 * @return true if all characters in the map are valid, false otherwise.
 */
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
