/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:35:24 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/27 14:54:26 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*get_img(t_game *game, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	img = NULL;

	texture = mlx_load_png(path);
	if(!texture)
	{
		ft_putstr_fd("get_img(): ERROR mlx_load_png\n", 2);
		// exit
	}

	img = mlx_texture_to_image(game->mlx, texture);
	if(!img)
	{
		ft_putstr_fd("get_img(): ERROR mlx_texture_to_image\n", 2);
		mlx_delete_texture(texture);
		// exit
	}

	mlx_delete_texture(texture);
	return (img);
}

void	load_textures(t_game *game)
{
	game->sprites->collectible = get_img(game, PATH_TO_COLLECTIBLE);
	game->sprites->wall = get_img(game, PATH_TO_WALL);
	game->sprites->exit = get_img(game, PATH_TO_EXIT);
	game->sprites->floor = get_img(game, PATH_TO_FLOOR);
	game->sprites->player = get_img(game, PATH_TO_PLAYER);

}
