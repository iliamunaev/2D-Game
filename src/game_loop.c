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

bool	check_collision(char **target, t_corner *corner)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((i == 0 && target[corner->tly][corner->t_left_x] == '1')
		|| (i == 1 && target[corner->try][corner->trx] == '1')
		|| (i == 2 && target[corner->bly][corner->blx] == '1')
		|| (i == 3 && target[corner->bry][corner->brx] == '1'))
			return (true);
		i++;
	}
	return (false);
}

void	get_next_position(t_position *pos, int dir, int axe)
{
	if (axe == AXE_X)
		pos->x += dir * STEP;
	else
		pos->y += dir * STEP;
}

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
		mlx_close_window(game->mlx);
}
