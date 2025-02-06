/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:41:09 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/06 12:48:42 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_collectible_instance(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < MAX_COLUMNS * MAX_ROWS)
	{
		if (game->sprites->collects->instances[i].x / TILE_SIZE == x
			&&game->sprites->collects->instances[i].y / TILE_SIZE == y)
			return (i);
		i++;
	}
	return (-1);
}

void	get_collectable(t_game *game, int y, int x)
{
	int	index;

	index = find_collectible_instance(game, x, y);
	if (index != -1)
	{
		game->map->map[y][x] = '0';
		game->sprites->collects->instances[index].enabled = false;
		game->collects--;
	}
}

void	check_collectibles(t_game *game, char **target, t_corner *corner)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((i == 0 && is_cltbl(target[corner->tly][corner->tlx]))
			|| (i == 1 && is_cltbl(target[corner->try][corner->trx]))
			|| (i == 2 && is_cltbl(target[corner->bly][corner->blx]))
			|| (i == 3 && is_cltbl(target[corner->bry][corner->brx])))
		{
			if (i == 0)
				get_collectable(game, corner->tly, corner->tlx);
			else if (i == 1)
				get_collectable(game, corner->try, corner->trx);
			else if (i == 2)
				get_collectable(game, corner->bly, corner->blx);
			else
				get_collectable(game, corner->bry, corner->brx);
		}
		i++;
	}
}

bool	check_exit(t_game *game, char **target, t_corner *corner)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((i == 0 && target[corner->tly][corner->tlx] == 'E') ||
			(i == 1 && target[corner->try][corner->trx] == 'E') ||
			(i == 2 && target[corner->bly][corner->blx] == 'E') ||
			(i == 3 && target[corner->bry][corner->brx] == 'E'))
		{
			if (game->collects == 0)
			{
				ft_printf("You win!\n");
				mlx_close_window(game->mlx);
				return (true);
			}
		}
		i++;
	}
	return (false);
}
