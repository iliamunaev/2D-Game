/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:23 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/01 11:56:51 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void key_handler(mlx_key_data_t keydata, void *param)
{
    t_game *game;
    int grid_x;
	int grid_y;

    game = (t_game *)param;
    grid_x = game->sprites->player->instances[0].x / TILE_SIZE;
    grid_y = game->sprites->player->instances[0].y / TILE_SIZE;

    if (keydata.action == MLX_PRESS)
    {
        if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
        {
            if (game->map->map[grid_y][grid_x + 1] != '1')
            {
                game->sprites->player->instances[0].x += STEP;
				game->moves++;
                ft_printf("Movements count: %d\n", game->moves);
            }
        }
        if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
        {
            if (game->map->map[grid_y][grid_x - 1] != '1')
            {
                game->sprites->player->instances[0].x -= STEP;
				game->moves++;
                ft_printf("Movements count: %d\n", game->moves);
            }
        }
        if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
        {
            if (game->map->map[grid_y + 1][grid_x] != '1')
            {
                game->sprites->player->instances[0].y += STEP;
				game->moves++;
                ft_printf("Movements count: %d\n", game->moves);
            }
        }
        if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
        {
            if (game->map->map[grid_y - 1][grid_x] != '1')
            {				
                game->sprites->player->instances[0].y -= STEP;
				game->moves++;
                ft_printf("Movements count: %d\n", game->moves);
            }
        }

        // Escape key to exit
        if (keydata.key == MLX_KEY_ESCAPE)
        {
            printf("See you!\n");
            //free_game_resources(game); // Ensure memory cleanup
            mlx_close_window(game->mlx);
        }
    }
}
