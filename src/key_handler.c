/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:23 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/01 16:16:05 by imunaev-         ###   ########.fr       */
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

void	process_action(t_game *game, char **target, int y, int x, int direction, int axe)
{
    if (axe == AXE_X)  
    {
        if (target[y][x + direction] != '1') 
        {
            if(target[y][x + direction] == 'E' && game->collects == 0)
            {
    	        ft_printf("You win!\n");
                //free_game_resources(game);
                mlx_close_window(game->mlx);
            } 
            game->sprites->player->instances[0].x += (STEP * direction);
            game->moves++;
            if (is_collectable(target[y][x + direction]))
                get_collectable(game, y, x + direction);
        }
    	ft_printf("Movements count: %d\n", game->moves);
    }
    else if (axe == AXE_Y)
    {
        if (target[y + direction][x] != '1')
        {
            if(target[y + direction][x] == 'E' && game->collects == 0)
            {
    	        ft_printf("You win!\n");
                //free_game_resources(game);
                mlx_close_window(game->mlx);
            } 
            game->sprites->player->instances[0].y += (STEP * direction);
            game->moves++;
            if (is_collectable(target[y + direction][x]))
                get_collectable(game, y + direction, x);
        }
    	ft_printf("Movements count: %d\n", game->moves);		
    }	
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
    t_game *game;
    int grid_x;
	int grid_y;
	char **target;
	
    game = (t_game *)param;
	target = game->map->map;
    grid_x = game->sprites->player->instances[0].x / TILE_SIZE;
    grid_y = game->sprites->player->instances[0].y / TILE_SIZE;
    if (keydata.action == MLX_PRESS)
    {
		if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			process_action(game, target, grid_y, grid_x, 1, AXE_X);   
        if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			process_action(game, target, grid_y, grid_x, -1, AXE_X);
        if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			process_action(game, target, grid_y, grid_x, 1, AXE_Y);
        if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			process_action(game, target, grid_y, grid_x, -1, AXE_Y);
        if (keydata.key == MLX_KEY_ESCAPE)
        {
            //free_game_resources(game); // Ensure memory cleanup
            mlx_close_window(game->mlx);
        }
    }
}