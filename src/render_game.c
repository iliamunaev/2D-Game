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

bool	render_sprite(t_game *game, char target, int row, int col)
{
	mlx_image_t	*sprite = NULL;

	if (target == 'G')
		sprite = game->sprites->grass;
	else if (target == 'P')
		sprite = game->sprites->player;
	else
		return (false);

	if (!sprite)
	{
		ft_putstr_fd("ERROR: render_sprite(): No valid sprite found\n", 2);
		return (false);
	}

	if (mlx_image_to_window(game->mlx, sprite, col * TILE_SIZE, row * TILE_SIZE) == -1)
	{
		ft_putstr_fd("ERROR: render_sprite(): mlx_image_to_window() failed\n", 2);
		return (false);
	}
	return (true);
}

bool	render(t_game *game, char target)
{
	int x; 
	int y; 
	char	**position;
	int counter_x = 0;
	int counter_y;

	x = 0;
	position = game->map->layout;

	while(counter_x < 5)
	{
		y = 0;
		counter_y = 0;
		while(counter_y < 5)
		{
			if(target == 'G')
			{
				if(!render_sprite(game, 'G', x, y))
					return (false);
			}
			else if(position[x][y] == target)
			{
				if(!render_sprite(game, target, x, y))
					return (false);
			}
			y++;
			counter_y++;
		}
		x++;
		counter_x++;
	}
	return (true);
}

bool	render_game(t_game *game)
{
	bool	is_grass_renderd;
	bool	is_player_rendered;

	if (!game->sprites)
	{
		ft_putstr_fd("ERROR: render_game(): game->sprites is NULL\n", 2);
		return (false);
	}
	else
		ft_putstr_fd("SUCCESS: render_game(): game->sprites -> ok\n", 2);

	
	is_grass_renderd = render(game, 'G');
	if(!is_grass_renderd)
	{		
		ft_putstr_fd("ERROR: render_game(): is_grass_renderd \n", 2);
		return (false);
	}
	else 
		ft_putstr_fd("SUCCESS: render_game(): is_grass_renderd -> ok\n", 2);


	is_player_rendered = render(game, 'P');
	if(!is_player_rendered)
	{		
		ft_putstr_fd("ERROR: render_game(): is_player_rendered \n", 2);
		return (false);
	}
	else 
		ft_putstr_fd("SUCCESS: render_game(): is_player_rendered -> ok\n", 2);


	ft_putstr_fd("SUCCESS: render_game(): render_game -> ok\n", 2);

	return (true);
}
