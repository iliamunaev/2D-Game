/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imunaev- <imunaev-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:36:07 by imunaev-          #+#    #+#             */
/*   Updated: 2025/01/26 20:32:34 by imunaev-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{

	t_game	*game;
	t_map	*map;
	t_monitor *monitor;

	if (ac != 2)
		clean_up_game(NULL, NULL, "Error: no map attached\n", EXIT_FAILURE);
	monitor = get_monitor_size();
	if(!monitor)
		clean_up_game(NULL, NULL, "Error: monitor size init failure\n", EXIT_FAILURE);
	map = load_map(av[1], monitor);
	if(!map)
		clean_up_game(NULL, NULL, "Error: map initialization failure\n", EXIT_FAILURE);
	free(monitor);
	game = init_game(map);
	if(!game)
		clean_up_game(game, map, "Error: game init failure\n", EXIT_FAILURE);
	if(game->running == true)
		render_game(game);
	else
		clean_up_game(game, NULL, NULL, EXIT_SUCCESS);
}
