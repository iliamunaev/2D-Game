/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:19:48 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/10 10:18:11 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Finds the starting position of the player on the map.
 *
 * Iterates through the map layout to locate the player ('P') and
 * stores the row and column position in the `start` structure.
 *
 * @param temp_map Pointer to the temporary map structure.
 * @param start Pointer to the structure that stores the player's start position.
 * @return EXIT_SUCCESS if the player is found, EXIT_FAILURE otherwise.
 */
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

/**
 * @brief Determines whether a given map position should be avoided.
 *
 * Checks if the given coordinates are out of bounds or contain an 
 * impassable character (wall, marked tiles, etc.).
 *
 * @param temp_map Pointer to the temporary map structure.
 * @param y Row coordinate.
 * @param x Column coordinate.
 * @return true if the position should be avoided, false otherwise.
 */
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

/**
 * @brief Marks reachable areas on the map using flood-fill.
 *
 * Recursively explores the map from the given coordinates, marking 
 * walkable tiles ('0'), collectibles ('C'), and exits ('E') with 
 * special characters to track accessibility.
 *
 * @param temp_map Pointer to the temporary map structure.
 * @param y Starting row coordinate.
 * @param x Starting column coordinate.
 */
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

/**
 * @brief Validates the number and accessibility of key game elements.
 *
 * Ensures that:
 * - There is exactly one player ('P') and one exit ('E').
 * - There is at least one collectible ('C').
 * - All collectibles and the exit are reachable from the player's
 * start position.
 *
 * If validation fails, an error message is printed.
 *
 * @param temp_map Pointer to the temporary map structure.
 * @param start Pointer to the starting position of the player.
 * @return true if validation is successful, false otherwise.
 */
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

/**
 * @brief Performs additional validation on the map.
 *
 * Checks if the player, exit, and collectibles are correctly placed and 
 * ensures that all required elements are reachable.
 *
 * @param temp_map Pointer to the temporary map structure.
 * @return true if the map passes additional validation, false otherwise.
 */
bool	additional_validation(t_temp_map *temp_map)
{
	t_start	start;

	if (get_start(temp_map, &start) == EXIT_FAILURE)
		return (false);
	if (!is_add_validate(temp_map, &start))
		return (false);
	return (true);
}
