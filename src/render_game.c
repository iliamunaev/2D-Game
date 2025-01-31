/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:33 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/30 12:45:00 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
bool	render_sprite(t_game *game, char target, int row, int col)
{
	mlx_image_t	*sprite = NULL;

	if (target == 'F')
		sprite = game->sprites->floor;
	else if (target == 'P')
		sprite = game->sprites->player;
	else if (target == 'W')
		sprite = game->sprites->wall;
	else if (target == 'C')
		sprite = game->sprites->collects;
	else if (target == 'E')
		sprite = game->sprites->exit;
	else
		return (false);

	if (!sprite)
	{
		ft_putstr_fd("ERROR: render_sprite(): No valid sprite found\n", 2);
		return (false);
	}

	if (mlx_image_to_window(game->mlx, sprite, col * TILE_SIZE, row * TILE_SIZE) == -1)
	{
		ft_putstr_fd("ERROR: render_sprite(): mlx_image_to_window() failed\n", 2);
		return (false);
	}
	return (true);
}

bool	render(t_game *game, char target)
{
	int x; 
	int y; 
	char	**position;

	y = 0;
	while(y < game->map->rows)
	{
		x = 0;
		while(y < game->map->cols)
		{
			if(target == 'F')
			{
				if(!render_sprite(game, 'F', x, y))
					return (false);
			}
			else if(game->map->map[x][y] == target)
			{
				if(!render_sprite(game, target, x, y))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

int	render_game(t_game *game, t_sprites *sprites)
{
	
	game->sprites = sprites;

	if (!game->sprites)
	{
		ft_putstr_fd("ERROR: render_game(): game->sprites is NULL\n", 2);
		return (EXIT_FAILURE);
	}
	else
		ft_putstr_fd("SUCCESS: render_game(): game->sprites -> ok\n", 2);

	if(render(game, 'F') == false) // floor
	{		
		ft_putstr_fd("ERROR: render_game(): floor \n", 2);
		return (EXIT_FAILURE);
	}
	else 
		ft_putstr_fd("SUCCESS: render_game(): floor -> ok\n", 2);


	if(render(game, '1') == false) // walls
	{		
		ft_putstr_fd("ERROR: render_game(): walls \n", 2);
		return (EXIT_FAILURE);
	}
	else 
		ft_putstr_fd("SUCCESS: render_game(): walls -> ok\n", 2);


	if(render(game, 'C') == false) // collectibles
	{		
		ft_putstr_fd("ERROR: render_game(): collectibles \n", 2);
		return (EXIT_FAILURE);
	}
	else 
		ft_putstr_fd("SUCCESS: render_game(): collectibles -> ok\n", 2);

	if(render(game, 'P') == false) // player
	{		
		ft_putstr_fd("ERROR: render_game(): player \n", 2);
		return (EXIT_FAILURE);
	}
	else 
		ft_putstr_fd("SUCCESS: render_game(): player -> ok\n", 2);

	if(render(game, 'E') == false) // exit
	{		
		ft_putstr_fd("ERROR: render_game(): exit \n", 2);
		return (EXIT_FAILURE);
	}
	else 
		ft_putstr_fd("SUCCESS: render_game(): exit -> ok\n", 2);
		

	ft_putstr_fd("SUCCESS: render_game(): render_game -> ok\n", 2);

	return (EXIT_SUCCESS);
}
*/



static bool	render_sprite(t_game *game, char target, int row, int col)
{
	mlx_image_t	*sprite = NULL;

	// Select correct sprite
	if (target == 'F')
		sprite = game->sprites->floor;
	else if (target == 'P')
		sprite = game->sprites->player;
	else if (target == 'W')
		sprite = game->sprites->wall;
	else if (target == 'C')
		sprite = game->sprites->collects;
	else if (target == 'E')
		sprite = game->sprites->exit;
	else
	{
		ft_putstr_fd("ERROR: render_sprite(): Invalid target character\n", 2);
		return (false);
	}

	// Ensure sprite is valid before rendering
	if (!sprite)
	{
		ft_putstr_fd("ERROR: render_sprite(): No valid sprite found\n", 2);
		return (false);
	}

	// Render to window
	if (mlx_image_to_window(game->mlx, sprite, col * TILE_SIZE, row * TILE_SIZE) == -1)
	{
		ft_putstr_fd("ERROR: render_sprite(): mlx_image_to_window() failed\n", 2);
		return (false);
	}
	return (true);
}

static bool	render(t_game *game, char target)
{
	int x, y;
	char **position = game->map->map; // Fix: Correct pointer reference

	// Loop through rows first, then columns
	for (y = 0; y < game->map->rows; y++)  
	{
		for (x = 0; x < game->map->cols; x++)  
		{
			if (position[y][x] == target) // Fix: Correct row/column order
			{
				if (!render_sprite(game, target, y, x))
				{
					ft_putstr_fd("ERROR: render(): Failed to render tile\n", 2);
					return (false);
				}
			}
		}
	}
	return (true);
}

int	render_game(t_game *game, t_sprites *sprites)
{
	game->sprites = sprites;

	if (!game->sprites)
	{
		ft_putstr_fd("ERROR: render_game(): game->sprites is NULL\n", 2);
		return (EXIT_FAILURE);
	}
	ft_putstr_fd("SUCCESS: render_game(): game->sprites -> ok\n", 2);

	// Render the floor first so everything else is drawn on top
	if (!render(game, 'F'))
	{		
		ft_putstr_fd("ERROR: render_game(): floor \n", 2);
		return (EXIT_FAILURE);
	}
	ft_putstr_fd("SUCCESS: render_game(): floor -> ok\n", 2);

	// Render walls
	if (!render(game, 'W'))
	{		
		ft_putstr_fd("ERROR: render_game(): walls \n", 2);
		return (EXIT_FAILURE);
	}
	ft_putstr_fd("SUCCESS: render_game(): walls -> ok\n", 2);

	// Render collectibles
	if (!render(game, 'C'))
	{		
		ft_putstr_fd("ERROR: render_game(): collectibles \n", 2);
		return (EXIT_FAILURE);
	}
	ft_putstr_fd("SUCCESS: render_game(): collectibles -> ok\n", 2);

	// Render player
	if (!render(game, 'P'))
	{		
		ft_putstr_fd("ERROR: render_game(): player \n", 2);
		return (EXIT_FAILURE);
	}
	ft_putstr_fd("SUCCESS: render_game(): player -> ok\n", 2);

	// Render exit
	if (!render(game, 'E'))
	{		
		ft_putstr_fd("ERROR: render_game(): exit \n", 2);
		return (EXIT_FAILURE);
	}
	ft_putstr_fd("SUCCESS: render_game(): exit -> ok\n", 2);

	ft_putstr_fd("SUCCESS: render_game(): Rendering complete\n", 2);
	return (EXIT_SUCCESS);
}
