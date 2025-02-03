/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:23 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/03 17:15:43 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_collectible_instance(t_game *game, int x, int y)
{
	int	i;
	
	i = 0;
	while(i < MAX_COLUMNS * MAX_ROWS) // replace to max num of collectbls
	{
        if (game->sprites->collects->instances[i].x / TILE_SIZE == x &&
            game->sprites->collects->instances[i].y / TILE_SIZE == y)
            return (i);
		i++;
    }
	return (-1);
}

void	get_collectable(t_game *game, int y, int x)
{
    int index;
	
	index = find_collectible_instance(game, x, y);
    if (index != -1)
    {
        game->map->map[y][x] = '0';
        game->sprites->collects->instances[index].enabled = false;
        game->collects--;
    }
}

bool		is_collectable(char collectable)
{
	return(collectable == 'C');
}

void process_action(t_game *game, char **target, int direction, int axe)
{
    int x, y, next_x, next_y;

    x = game->sprites->player->instances[0].x;
    y = game->sprites->player->instances[0].y;

    if (axe == AXE_Y)
    {
        next_x = x;
        next_y = y + direction * STEP;		
    }
    else
    {
        next_x = x + direction * STEP;
        next_y = y;		
    }

    // Compute all 4 corner positions
    int next_grid_top_left_x  = next_x / TILE_SIZE;
    int next_grid_top_left_y  = next_y / TILE_SIZE;

    int next_grid_top_right_x  = (next_x + TILE_SIZE - 1) / TILE_SIZE;
    int next_grid_top_right_y  = next_y / TILE_SIZE;

    int next_grid_bottom_left_x  = next_x / TILE_SIZE;
    int next_grid_bottom_left_y  = (next_y + TILE_SIZE - 1) / TILE_SIZE;

    int next_grid_bottom_right_x  = (next_x + TILE_SIZE - 1) / TILE_SIZE;
    int next_grid_bottom_right_y  = (next_y + TILE_SIZE - 1) / TILE_SIZE;


	
    if (target[next_grid_top_left_y][next_grid_top_left_x] == '1' ||
        target[next_grid_top_right_y][next_grid_top_right_x] == '1' ||
        target[next_grid_bottom_left_y][next_grid_bottom_left_x] == '1' ||
        target[next_grid_bottom_right_y][next_grid_bottom_right_x] == '1')
    {
        return ;
    }

    // Convert new position to grid coordinates
    int next_grid_x = next_x / TILE_SIZE;
    int next_grid_y = next_y / TILE_SIZE;

    // Collectible check
    if (is_collectable(target[next_grid_y][next_grid_x]))
        get_collectable(game, next_grid_y, next_grid_x);

    // is_collectable
    if (target[next_grid_y][next_grid_x] == 'E' && game->collects == 0)
    {
        ft_printf("You win!\n");
        mlx_close_window(game->mlx);
        return;
    }

    game->sprites->player->instances[0].x = next_x;
    game->sprites->player->instances[0].y = next_y;
    game->moves++;
    
    ft_printf("Movements count: %d\n", game->moves);
}



void game_loop(void *param)
{
    t_game *game = (t_game *)param;
    char **target = game->map->map;

    if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(game->mlx, MLX_KEY_D))
        process_action(game, target,  1, AXE_X);
    if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) || mlx_is_key_down(game->mlx, MLX_KEY_A))
        process_action(game, target,  -1, AXE_X);
    if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN) || mlx_is_key_down(game->mlx, MLX_KEY_S))
        process_action(game, target,  1, AXE_Y);
    if (mlx_is_key_down(game->mlx, MLX_KEY_UP) || mlx_is_key_down(game->mlx, MLX_KEY_W))
        process_action(game, target,  -1, AXE_Y);
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
    {
      //  free_game_resources(game);
        mlx_close_window(game->mlx);
    }
}
