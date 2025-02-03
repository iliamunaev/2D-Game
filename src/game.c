/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:23 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/03 19:16:42 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_collectible_instance(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < MAX_COLUMNS * MAX_ROWS) // replace to max num of collectbls
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
    int	index;
	
	index = find_collectible_instance(game, x, y);
    if (index != -1)
    {
        game->map->map[y][x] = '0';
        game->sprites->collects->instances[index].enabled = false;
        game->collects--;
    }
}

bool	is_collectable(char collectable)
{
	return(collectable == 'C');
}


void	get_next_position(int *next_x, int *next_y, int x, int y, int direction, int axe)
{
	if(axe == AXE_X)
	{
		*next_x = x + direction * STEP;
		*next_y = y;
	}
	if(axe == AXE_Y)
	{
		*next_x = x;
		*next_y = y + direction * STEP;
	}
}

t_corner *init_corners(int next_x, int next_y)
{
    t_corner *corner;
	
	corner = malloc(sizeof(t_corner));
    if (!corner)
        return (NULL);
    corner->top_left_x = next_x / TILE_SIZE;
    corner->top_left_y = next_y / TILE_SIZE;
    corner->top_right_x = (next_x + TILE_SIZE - 1) / TILE_SIZE;
    corner->top_right_y = next_y / TILE_SIZE;
    corner->bottom_left_x = next_x / TILE_SIZE;
    corner->bottom_left_y = (next_y + TILE_SIZE - 1) / TILE_SIZE;
    corner->bottom_right_x = (next_x + TILE_SIZE - 1) / TILE_SIZE;
    corner->bottom_right_y = (next_y + TILE_SIZE - 1) / TILE_SIZE;

    return (corner);
}

bool	check_collision(char **target, t_corner *corner)
{
    int	i;
	
	i = 0;
    while (i < 4)
    {
        if ((i == 0 && target[corner->top_left_y][corner->top_left_x] == '1') ||
            (i == 1 && target[corner->top_right_y][corner->top_right_x] == '1') ||
            (i == 2 && target[corner->bottom_left_y][corner->bottom_left_x] == '1') ||
            (i == 3 && target[corner->bottom_right_y][corner->bottom_right_x] == '1'))
            return (true);
        i++;
    }
    return (false);
}

void	move_player(t_game *game, int next_x, int next_y)
{
    game->sprites->player->instances[0].x = next_x;
    game->sprites->player->instances[0].y = next_y;
    game->moves++;
    ft_printf("Movements count: %d\n", game->moves);
}

void	check_collectibles(t_game *game, char **target, t_corner *corner)
{
    int	i;
	
	i = 0;
    while (i < 4)
    {
        if ((i == 0 && is_collectable(target[corner->top_left_y][corner->top_left_x])) ||
            (i == 1 && is_collectable(target[corner->top_right_y][corner->top_right_x])) ||
            (i == 2 && is_collectable(target[corner->bottom_left_y][corner->bottom_left_x])) ||
            (i == 3 && is_collectable(target[corner->bottom_right_y][corner->bottom_right_x])))
        {
            if (i == 0) get_collectable(game, corner->top_left_y, corner->top_left_x);
            else if (i == 1) get_collectable(game, corner->top_right_y, corner->top_right_x);
            else if (i == 2) get_collectable(game, corner->bottom_left_y, corner->bottom_left_x);
            else get_collectable(game, corner->bottom_right_y, corner->bottom_right_x);
        }
        i++;
    }
}

bool	check_exit(t_game *game, char **target, t_corner *corner)
{
	int	i;
	
	i = 0;
	while (i < 4)
	{
		if ((i == 0 && target[corner->top_left_y][corner->top_left_x] == 'E') ||
			(i == 1 && target[corner->top_right_y][corner->top_right_x] == 'E') ||
			(i == 2 && target[corner->bottom_left_y][corner->bottom_left_x] == 'E') ||
			(i == 3 && target[corner->bottom_right_y][corner->bottom_right_x] == 'E'))
		{
			if (game->collects == 0)
			{
				ft_printf("You win!\n");
				mlx_close_window(game->mlx);
				return (true);
            }
        }
        i++;
    }
    return (false);
}

void process_action(t_game *game, char **target, int direction, int axe)
{
	int			x;
	int			y;
	int			next_x;
	int			next_y;
	t_corner *corner;

	y = game->sprites->player->instances[0].y;
	x = game->sprites->player->instances[0].x;
	get_next_position(&next_x, &next_y, x, y, direction, axe);
	corner = init_corners(next_x, next_y);
	if (!corner)
		return ;
	if (check_collision(target, corner))
	{
		free(corner);
		return ;
	}
	move_player(game, next_x, next_y);
	check_collectibles(game, target, corner);
	if (check_exit(game, target, corner))
    {
		free(corner);
		return ;
	}
	free(corner);
}


void game_loop(void *param)
{
	t_game	*game;
	char	**target;
		
	game = (t_game *)param;
	target = game->map->map;
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
