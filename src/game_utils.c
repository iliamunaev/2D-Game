/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_uutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:41:29 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/04 13:41:42 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

bool	is_collectable(char collectable)
{
	return(collectable == 'C');
}