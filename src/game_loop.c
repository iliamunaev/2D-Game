/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:23 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/03 19:16:42 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Checks for a collision at the given corner positions.
 *
 * Iterates through the four corner positions of an entity to determine
 * if any of them collide with a wall ('1') in the target map.
 *
 * @param target 2D array representing the game map.
 * @param corner Pointer to the structure containing the corner positions.
 * @return true if a collision is detected, false otherwise.
 */
bool	check_collision(char **target, t_corner *corner)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((i == 0 && target[corner->tly][corner->tlx] == '1')
		|| (i == 1 && target[corner->try][corner->trx] == '1')
		|| (i == 2 && target[corner->bly][corner->blx] == '1')
		|| (i == 3 && target[corner->bry][corner->brx] == '1'))
			return (true);
		i++;
	}
	return (false);
}

/**
 * @brief Updates the next position based on direction and axis.
 *
 * Adjusts the x or y coordinate of a position based on the movement
 * direction and axis of movement.
 *
 * @param pos Pointer to the position structure to update.
 * @param dir Direction of movement (-1 for left/up, 1 for right/down).
 * @param axe Movement axis (AXE_X for horizontal, AXE_Y for vertical).
 */
void	get_next_position(t_position *pos, int dir, int axe)
{
	if (axe == AXE_X)
		pos->x += dir * STEP;
	else
		pos->y += dir * STEP;
}

/**
 * @brief Processes the player's movement and interactions.
 *
 * Computes the next position based on input direction and axis,
 * checks for collisions, moves the player if no obstacles exist,
 * and processes collectibles and exit conditions.
 *
 * @param game Pointer to the game structure.
 * @param target 2D array representing the game map.
 * @param dir Direction of movement (-1 for left/up, 1 for right/down).
 * @param axe Movement axis (AXE_X for horizontal, AXE_Y for vertical).
 */
void	process_action(t_game *game, char **target, int dir, int axe)
{
	t_position	pos;
	t_position	next;
	t_corner	corner;

	pos.y = game->sprites->player->instances[0].y;
	pos.x = game->sprites->player->instances[0].x;
	next = pos;
	get_next_position(&next, dir, axe);
	init_corners(&corner, next.x, next.y);
	if (check_collision(target, &corner))
		return ;
	move_player(game, next.x, next.y);
	check_collectibles(game, target, &corner);
	if (check_exit(game, target, &corner))
		return ;
}

/**
 * @brief Main game loop that processes player input and actions.
 *
 * Checks for key presses and calls `process_action()` accordingly
 * to move the player in different directions. Also listens for
 * the escape key to close the game window.
 *
 * @param param Pointer to the game structure.
 */
void	game_loop(void *param)
{
	t_game	*game;
	char	**target;

	game = (t_game *)param;
	target = game->map->map;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_D))
		process_action(game, target, 1, AXE_X);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_A))
		process_action(game, target, -1, AXE_X);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(game->mlx, MLX_KEY_S))
		process_action(game, target, 1, AXE_Y);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(game->mlx, MLX_KEY_W))
		process_action(game, target, -1, AXE_Y);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
	}
}
