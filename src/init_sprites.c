/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:20:28 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/10 10:17:20 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Loads an image texture from a file and converts it to an MLX image.
 *
 * Loads a PNG texture using `mlx_load_png()` and converts it to an MLX image 
 * using `mlx_texture_to_image()`. Cleans up the texture after conversion.
 *
 * @param game Pointer to the game structure.
 * @param path_to_sprite Path to the sprite image file.
 * @return Pointer to the created MLX image, or NULL on failure.
 */
static mlx_image_t	*get_img(t_game *game, const char *path_to_sprite)
{
	mlx_texture_t	*texture;
	mlx_image_t		*sprite;

	texture = mlx_load_png(path_to_sprite);
	if (!texture)
	{
		ft_putstr_fd("Error: get_img -> mlx_load_png failed.\n", 2);
		return (NULL);
	}
	sprite = mlx_texture_to_image(game->mlx, texture);
	if (!sprite)
	{
		ft_putstr_fd("Error: get_img -> mlx_texture_to_image tfailed.\n", 2);
		mlx_delete_texture(texture);
		return (NULL);
	}
	mlx_delete_texture(texture);
	return (sprite);
}

/**
 * @brief Loads all necessary game textures.
 *
 * Calls `get_img()` to load and assign textures for the player, floor, wall, 
 * collectibles, and exit. If any texture fails to load, an error is printed.
 *
 * @param game Pointer to the game structure.
 * @param sprites Pointer to the sprite structure.
 * @return EXIT_SUCCESS if all textures are loaded successfully,
 * EXIT_FAILURE otherwise.
 */
static int	load_textures(t_game *game, t_sprites *sprites)
{
	sprites->player = get_img(game, PATH_TO_PLAYER);
	sprites->floor = get_img(game, PATH_TO_FLOOR);
	sprites->wall = get_img(game, PATH_TO_WALL);
	sprites->collects = get_img(game, PATH_TO_COLLECTIBLE);
	sprites->exit = get_img(game, PATH_TO_EXIT);
	if (!(sprites->player && sprites->floor && sprites->wall
			&& sprites->collects && sprites->exit))
	{
		ft_putstr_fd("Error: load_textures -> load textures failed\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief Allocates and loads game sprites.
 *
 * Allocates memory for the `t_sprites` structure and initializes all 
 * sprite pointers to NULL. Calls `load_textures()` to load textures.
 * If loading fails, cleans up and returns NULL.
 *
 * @param game Pointer to the game structure.
 * @return Pointer to the initialized sprite structure, or NULL on failure.
 */
static t_sprites	*load_sprites(t_game *game)
{
	t_sprites	*sprites;

	sprites = malloc(sizeof(t_sprites));
	if (!sprites)
	{
		ft_putstr_fd("Error: sprites memory allocation failed\n", 2);
		return (NULL);
	}
	sprites->player = NULL;
	sprites->floor = NULL;
	sprites->wall = NULL;
	sprites->collects = NULL;
	sprites->exit = NULL;
	if (load_textures(game, sprites) == EXIT_FAILURE)
	{
		free(sprites);
		ft_putstr_fd("ERROR: load_sprites(): load_textures\n", 2);
		return (NULL);
	}
	return (sprites);
}

/**
 * @brief Initializes all game sprites.
 *
 * Calls `load_sprites()` to load textures and create sprite objects. 
 * If initialization fails, cleans up MLX, frees the map, and
 * terminates the game.
 *
 * @param game Pointer to the game structure.
 * @return Pointer to the initialized sprite structure, or NULL on failure.
 */
t_sprites	*init_sprites(t_game *game)
{
	t_sprites	*sprites;

	sprites = load_sprites(game);
	if (!sprites)
	{
		mlx_terminate(game->mlx);
		free_map(game->map);
		free(game);
		return (NULL);
	}
	return (sprites);
}
