/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/26 14:28:13 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{

	t_game	*game;
	t_map	*map;

	if (ac != 2)
	{
		ft_putstr_fd("Error: arg != 2\n",2);
		return (EXIT_FAILURE);
	}


	// Step 2: Validate map and load layout
	map = load_map(av[1]);

	if(!map)
	{
		clean_up_game(NULL, map);
		ft_putstr_fd("Error: map is not valid\n",2);
		return (EXIT_FAILURE);
	}

	// Step 2:
	game = init_game(map);
	if(game == -1)
	{
		clean_up_game(game, map);
		return (EXIT_FAILURE);
	}

	// Step 3:

	while (game->running)
	{
		handle_input_loop(game);
		render_game(game);
	}

	clean_up_game(game, NULL);

	return (EXIT_SUCCESS);
}
