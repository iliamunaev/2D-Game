/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:33 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/30 12:45:00 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	render_sprite(t_game *game, char target, int row, int col)
{
	mlx_image_t	*sprite;

	sprite = NULL;
	if (target == '0')
		sprite = game->sprites->floor;
	else if (target == '1')
		sprite = game->sprites->wall;
	else if (target == 'C')
		sprite = game->sprites->collects;
	else if (target == 'E')
		sprite = game->sprites->exit;
	else if (target == 'P')
		sprite = game->sprites->player;
	if (!sprite)
	{
		ft_putstr_fd("Error: assign sprite ptr to game failed\n", 2);
		return (false);
	}
	if (mlx_image_to_window(game->mlx, sprite,
			col * TILE_SIZE, row * TILE_SIZE) == -1)
	{
		ft_putstr_fd("Error: render_sprite -> mlx_image_to_window failed\n", 2);
		return (false);
	}
	return (true);
}

static bool	render(t_game *game, char target)
{
	int		x;
	int		y;
	char	**position;

	position = game->map->map;
	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			if (position[y][x] == target)
			{
				if (!render_sprite(game, target, y, x))
				{
					ft_putstr_fd("Error: render -> tiles failed\n", 2);
					return (false);
				}
			}
			x++;
		}
		y++;
	}
	return (true);
}

static bool	render_floor(t_game *game, char target)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			if (!render_sprite(game, target, y, x))
			{
				ft_putstr_fd("Error: render_floor -> failed\n", 2);
				return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

int	render_game(t_game *game, t_sprites *sprites)
{
	game->sprites = sprites;
	if (!render_floor(game, '0'))
		return (EXIT_FAILURE);
	if (!render(game, '1'))
		return (EXIT_FAILURE);
	if (!render(game, 'C'))
		return (EXIT_FAILURE);
	if (!render(game, 'E'))
		return (EXIT_FAILURE);
	if (!render(game, 'P'))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
