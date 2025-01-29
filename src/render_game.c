/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:33 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/29 18:23:32 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
	
bool 	render_player(t_game *game)
{
	if (mlx_image_to_window(game->mlx, game->sprites->player, 0, 0) == -1)
	{
		mlx_close_window(game->mlx);
		ft_putstr_fd("ERROR: mlx_image_to_window\n", 2);
		return(false);
	}
	else 
	{
		ft_putstr_fd("SUCCESS: render_game(): mlx_image_to_window -> ok\n", 2);  // test
	}	
	return (true);
}
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
bool 	render_grass(t_game *game)
{
	//flood_fill();

	
	if (mlx_image_to_window(game->mlx, game->sprites->grass, 0, 0) == -1)
	{
		mlx_close_window(game->mlx);
		ft_putstr_fd("ERROR: mlx_image_to_window\n", 2);
		return(false);
	}
	else 
	{
		ft_putstr_fd("SUCCESS: render_game(): mlx_image_to_window -> ok\n", 2);  // test
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
	else
		ft_putstr_fd("SUCCESS: render_game(): game->sprites -> ok\n", 2);
	
	if(!render_grass(game))
	{
		ft_putstr_fd("ERROR: render_game(): render_grass() fail\n", 2);
		return (false);
	}
	else 
		ft_putstr_fd("SUCCESS: render_game(): render_grass() -> ok\n", 2);
		
	
	if(!render_player(game))
	{
		ft_putstr_fd("ERROR: render_game(): render_player() fail\n", 2);
		return (false);
	}
	else 
		ft_putstr_fd("SUCCESS: render_game(): render_player() -> ok\n", 2);
		


	return (true);
}



