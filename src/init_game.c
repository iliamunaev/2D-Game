/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:29 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/29 16:42:23 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


t_game	*init_game()
{
	
	t_position	*position;
	t_sprites	*sprites;
	t_game	*game;

	sprites = malloc(sizeof(t_sprites));
	if(!sprites)
	{
		ft_putstr_fd("ERROR: init_game(): sprites memory allocation failed\n", 2);
		return (NULL);
	}
	else 
		ft_putstr_fd("SUCCESS: init_game(): sprites memory allocation -> ok\n", 2);  // test
	
	position = malloc(sizeof(t_position));
	if(!position)
	{
		ft_putstr_fd("ERROR: init_game(): position memory allocation failed\n", 2);
		return (NULL);
	}
	else 
		ft_putstr_fd("SUCCESS: init_game(): position memory allocation -> ok\n", 2);  // test


	game = malloc(sizeof(t_game));
	if(!game)
	{
		ft_putstr_fd("ERROR: init_game(): game memory allocation failed\n", 2);
		return (NULL);
	}
	else
		ft_putstr_fd("SUCCESS: init_game(): game memory allocation -> ok\n", 2);  // test

	game->running = 0;
	sprites->player = NULL;
	game->sprites = sprites;	
	position->x = 0;
	position->y = 0;	
	game->sprites->player_position = position;

	return (game);
}