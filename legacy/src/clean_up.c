/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:45:54 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/27 13:59:40 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clean_up_map(t_map *map)
{
	if(map)
	{
		if(map->layout)
		{

		}
	}
	free(map->layout);
	free(map);
}

static void	clean_up_sprites(t_sprites *sprites)
{
	if(sprites->wall)
		free(sprites->wall);
	if(sprites->floor)
		free(sprites->floor);
	if(sprites->player)
		free(sprites->player);
	if(sprites->collectible)
		free(sprites->collectible);
	if(sprites->exit)
		free(sprites->exit);
	free(sprites);
}

int	clean_up_game(t_game *game, t_map *map, char *msg, int exit_mark)
{
	if(game)
	{
		if(game->map)
			clean_up_map(game->map);
		if (game->sprites)
			clean_up_sprites(game->sprites);
		if (game->player)
			free(game->player);
		mlx_terminate(game->mlx);
		free(game->mlx);
		free(game);
	}
	if(map)
		clean_up_map(map);
	if(msg)
		ft_putstr_fd(msg,2);
	if(exit_mark)
		return(exit_mark);
	return (0);
}
