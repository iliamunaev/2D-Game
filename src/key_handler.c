/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:23 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/01 11:26:53 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void key_handler(mlx_key_data_t keydata, void *param)
{
    t_game *game;
    int32_t pos_x, pos_y;
    int grid_x, grid_y;

    game = (t_game *)param;
    pos_x = game->sprites->player->instances[0].x;
    pos_y = game->sprites->player->instances[0].y;

    // Convert pixel coordinates to grid index
    grid_x = pos_x / TILE_SIZE;
    grid_y = pos_y / TILE_SIZE;

    // Check if a key is pressed (not held)
    if (keydata.action == MLX_PRESS)
    {
        if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
        {
            if (game->map->map[grid_y][grid_x + 1] != '1') // Prevent moving into walls
            {
                game->sprites->player->instances[0].x += STEP;
                printf("Move to Right");
            }
        }
        if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
        {
            if (game->map->map[grid_y][grid_x - 1] != '1')
            {
                game->sprites->player->instances[0].x -= STEP;

                printf("Move to Left - Moves");
            }
        }
        if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
        {
            if (game->map->map[grid_y + 1][grid_x] != '1')
            {
                game->sprites->player->instances[0].y += STEP;

                printf("Move to Down - Moves");
            }
        }
        if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
        {
            if (game->map->map[grid_y - 1][grid_x] != '1')
            {
                game->sprites->player->instances[0].y -= STEP;
                printf("Move to Up - Moves");
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
