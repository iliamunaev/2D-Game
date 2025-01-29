/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:35:24 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/29 15:51:08 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// in case of faier all must be free here
mlx_image_t	*get_img(t_game *game, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*sprite;

	if (!game || !game->mlx || !game->sprites)
	{
		ft_putstr_fd("ERROR: get_img(): Invalid game, mlx or sprites context\n", 2);
		return (NULL);
	}
	else
		ft_putstr_fd("SUCCESS: get_img(): game, mlx or sprites -> ok\n", 2);
	
	texture = mlx_load_png(path);

	if(!texture)
	{
		ft_putstr_fd("ERROR: get_img(): mlx_load_png() load png file fail\n", 2);
		return (NULL);
	}
	else 
		ft_putstr_fd("SUCCESS: get_img(): mlx_load_png() load png file -> ok\n", 2);
		

	sprite = mlx_texture_to_image(game->mlx, texture);
	if(!sprite)
	{
		ft_putstr_fd("ERROR: get_img(): mlx_texture_to_image() texture to img fail\n", 2);
		mlx_delete_texture(texture);
		return (NULL);
	}
	else 
		ft_putstr_fd("SUCCESS: get_img(): mlx_texture_to_image() texture to img -> ok\n", 2);

	mlx_delete_texture(texture);
	
	printf("INFO: get_img() sprite memory add: %p\n", sprite); // test
	return (sprite);
}


bool	load_textures(t_game *game)
{
	game->sprites->player = get_img(game, PATH_TO_PLAYER);
	
	printf("INFO: load_textures() sprite memory add: %p\n", game->sprites->player);  // test
	

	if(!game->sprites->player)
	{
		ft_putstr_fd("ERROR: load_textures(): load some textures failed\n", 2);
		return (false);
	}
	else 
		ft_putstr_fd("SUCCESS: load_textures(): load textures -> ok\n", 2); // test
				
	return (true);
}
