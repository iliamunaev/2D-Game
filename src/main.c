/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/26 17:41:03 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{

	t_game	*game;
	t_map	*map;

	if (ac != 2)
		clean_up_game(NULL, NULL, "Error: arg != 2\n", EXIT_FAILURE);

	map = load_map(av[1]);
	if(!map)
		clean_up_game(NULL, map, "Error: map is not valid\n", EXIT_FAILURE);

	game = init_game(map);
	if(game == EXIT_FAILURE)
		clean_up_game(game, map, "Error: game init failure\n", EXIT_FAILURE);

	if(game->running == true)
		render_game(game);
	else
		clean_up_game(game, NULL, NULL, EXIT_FAILURE);
}
