/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:20:28 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/31 16:05:30 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*get_img(t_game *game, const char *path_to_sprite)
{
	mlx_texture_t	*texture;
	mlx_image_t		*sprite;

	texture = mlx_load_png(path_to_sprite);
	if(!texture)
	{
		ft_putstr_fd("ERROR: get_img(): mlx_load_png() fail\n", 2);
		return (NULL);
	}
	else 
		ft_putstr_fd("SUCCESS: get_img(): mlx_load_png() load png file\n", 2);
		

	sprite = mlx_texture_to_image(game->mlx, texture);
	if(!sprite)
	{
		ft_putstr_fd("ERROR: get_img(): mlx_texture_to_image() texture to img fail\n", 2);
		mlx_delete_texture(texture);
		return (NULL);
	}
	else 
		ft_putstr_fd("SUCCESS: get_img(): mlx_texture_to_image() texture to img\n", 2);

	mlx_delete_texture(texture);
	
	return (sprite);
}


static int	load_textures(t_game *game, t_sprites *sprites)
{
	sprites->player = get_img(game, PATH_TO_PLAYER);
	sprites->floor = get_img(game, PATH_TO_FLOOR);
	sprites->wall = get_img(game, PATH_TO_WALL);
	sprites->collects = get_img(game, PATH_TO_COLLECTIBLE);
	sprites->exit = get_img(game, PATH_TO_EXIT);	

	if(!(sprites->player && sprites->floor && sprites->wall
		&& sprites->collects && sprites->exit))
	{
		ft_putstr_fd("ERROR: load_textures(): load some textures failed\n", 2);
		return (INIT_ERROR);
	}
	else 
		ft_putstr_fd("SUCCESS: load_textures(): load textures -> ok\n", 2); // test
				
	return (INIT_SUCCESS);
}

t_sprites	*load_sprites(t_game *game)
{
	t_sprites	*sprites;

	sprites = malloc(sizeof(t_sprites));
	if(!sprites)
	{
		ft_putstr_fd("ERROR: load_sprites(): sprites memory allocation failed\n", 2);
		return (NULL);
	}
	else 
		ft_putstr_fd("SUCCESS: load_sprites(): sprites memory allocation -> ok\n", 2);  // test
	
	sprites->player = NULL;
	sprites->floor = NULL;
	sprites->wall = NULL;
	sprites->collects = NULL;
	sprites->exit = NULL;

	if(load_textures(game, sprites) == INIT_ERROR)
	{
		ft_putstr_fd("ERROR: load_sprites(): load_textures\n", 2);
		return (NULL);
	}
	else 
		ft_putstr_fd("SUCCESS: load_sprites(): load_texturesk\n", 2); 

	return (sprites);
}