/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:33 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/30 11:51:54 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
	
/*
void	flood_fill(t_game *game, char target, int row, int col)
{
	if(col < 0 || row < 0 || col >= MAX_COLUMNS || row >= MAX_ROWS)
		return ;
	render_tile(game, row, col);
	flood_fill(game, target, row + 1, col);
	flood_fill(game, target, row, col + 1);
	flood_fill(game, target, row - 1, col);
	flood_fill(game, target, row, col - 1);
}
*/

static bool	render_sprite(t_game *game, mlx_image_t *sprite)
{
	if (mlx_image_to_window(game->mlx, sprite, 0, 0) == -1)
	{
		mlx_close_window(game->mlx);
		ft_putstr_fd("ERROR: render_sprite failure\n", 2);
		return(false);
	}	
	return (true);
}

bool	render_game(t_game *game)
{	
	if (!game->sprites)
	{
		ft_putstr_fd("ERROR: render_game(): game->sprites is NULL\n", 2);
		return (false);
	}	
	//flood_fill();

	render_sprite(game, game->sprites->grass);
	render_sprite(game, game->sprites->player);
	
	// render_sprite(game, '1');
	// render_sprite(game, 'C');
	// render_sprite(game, 'E');



	return (true);
}



