/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:23 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/29 16:45:07 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void key_handler(void *param)
{
    t_game *game;
	
	game = (t_game *)param;

    
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		game->sprites->player_position->x += SPRITE_SIZE;
		printf("Move to Right\n");
	}		
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) || mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		game->sprites->player_position->x -= SPRITE_SIZE;
		printf("Move to Left\n");
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN) || mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		game->sprites->player_position->y -= SPRITE_SIZE;
		printf("Move to Down\n");
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP) || mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		game->sprites->player_position->y += SPRITE_SIZE;
		printf("Move to Up\n");
	}
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
    {
        mlx_close_window(game->mlx);
		mlx_delete_image(game->mlx, game->sprites->player);
		printf("See you!\n");
    }
}