/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@studen.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:55:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/02/04 18:53:34 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
void	restore_temp_map(temp_map)
{
	
}

bool	is_char_mathed(t_temp_map *temp_map, char target, int row, int col)
{

	if(temp_map->layout[row][col] != target)
	{
	}
	
	if (temp_map->layout[row][col] == target)
	{
		restore_temp_map(temp_map);
		return (true);
	}
	is_char_mathed(temp_map, target, row, col);
	
}
	
bool	find_path(t_temp_map *temp_map, int row, int col)
{
	char	target;
	bool	path;

	target = 'E';		
	path = is_char_mathed(temp_map, target, row, col);
	return (path);		
}
bool	is_exit_available(t_temp_map *temp_map)
{
	int	y;
	int	x;

	y = 0;
	while(temp_map->layout[y])
	{
		x = 0;
		while(temp_map->layout[y][x])
		{
			if(temp_map->layout[y][x] == 'P')
				break ;
			x++;
		}
		y++;
	}
	if(!find_path(temp_map, y, x))
	{
		ft_putstr_fd("Error: Left wall not closed!\n", 2);
		return (false);		
	}
		
}
*/
bool	is_left_n_right_wall(t_temp_map *temp_map)
{
	int	i;
	
	i = 0;
	while (temp_map->layout[i])
	{
		if(temp_map->layout[i][0] != '1')
		{
        	ft_putstr_fd("Error: Left wall not closed!\n", 2);
			return (false);	
		}
		if(temp_map->layout[i][temp_map->cols - 1] != '1')
		{
        	ft_putstr_fd("Error: Right wall not closed.\n", 2);
			return (false);	
		}
		i++;
	}
	return (true);
}

bool	is_walls(t_temp_map *temp_map)
{	
    if (!ft_is_char_arr_solid(temp_map->layout[0], '1'))
    {
        ft_putstr_fd("Error: Top wall not closed.\n", 2);
        return (false);
    }
    if (!ft_is_char_arr_solid(temp_map->layout[temp_map->rows - 1], '1'))
    {
        ft_putstr_fd("Error: Bottom wall not closed.\n", 2);
        return (false);
    }
	if(!is_left_n_right_wall(temp_map))
	{
        return (false);
    }
	return(true);

}

bool	is_exit(t_temp_map *temp_map)
{
	int exit;

	exit = ft_parse_char_2d_arr(temp_map->layout, EXIT);
	if(exit != 1)
	{
		ft_putstr_fd("error: No exit or exits more then one.\n",  2);
		return (false);
	}
	return(true);
}

bool	is_player(t_temp_map *temp_map)
{
	int	player;

	player = ft_parse_char_2d_arr(temp_map->layout, PLAYER);
	if(player != 1)
	{
		ft_putstr_fd("Error: No player or players more then one.\n",  2);
		return (false);
	}
	return(true);
}

bool	is_collectibles(t_temp_map *temp_map)
{
	int	collectaibles;

	collectaibles = ft_parse_char_2d_arr(temp_map->layout, COLLECTIBLE);
	if(collectaibles < 1)
	{
		ft_putstr_fd("Error: Number of collectaibles less then one.\n",  2);
		return (false);
	}
	temp_map->collects = collectaibles;
	return(true);	
}

bool	is_invalid_char(t_temp_map *temp_map)
{
	int		i;
	int		j;
	char 	**arr;

	i = 0;
	arr = temp_map->layout;	
	while (arr[i])
	{
		j = 0;
		while(arr[i][j])
		{
			if(!(arr[i][j] == '0' 
				|| arr[i][j] == '1'
				|| arr[i][j] == 'P'
				|| arr[i][j] == 'E'
				|| arr[i][j] == 'C'))
				{
					ft_putstr_fd("Error: The map contain invalid char.\n", 2);
					return (false);			
				}
			j++;
		}
		i++;
	}	
	return(true);
}

bool	is_in_max_columns(t_temp_map *temp_map)
{
	if(temp_map->cols > MAX_COLUMNS)
	{
		ft_putstr_fd("Error: Number of columns more then max.\n",  2);
		return (false);
	}
	return(true);
}

bool	is_rectangular(t_temp_map *temp_map)
{
	int	len_sample;
	int	str_len;
	int i;
	
	len_sample = ft_strlen(temp_map->layout[0]);
	i = 0;
	while(temp_map->layout[i])
	{
		str_len = ft_strlen(temp_map->layout[i]);
		if(str_len != len_sample)
		{
			ft_putstr_fd("Error: The map is not rectangular.\n",  2);
			return (false);
		}
		i++;
	}
	return (true);
}

bool  is_valid(t_temp_map *temp_map)
{
	if (is_invalid_char(temp_map)  // tested
		&& is_collectibles(temp_map) // tested
		&& is_player(temp_map) // tested
		&& is_exit(temp_map) // tested
		&& is_walls(temp_map) // tested
		&& is_in_max_columns(temp_map) // tested
		&& is_rectangular(temp_map)) // rested
		{
			return (true);			
		}
	return (false);	
}
