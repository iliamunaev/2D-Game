#include "so_long.h"
	
bool	render_game(t_game *game)
{	
	if (!game->sprites)
	{
		ft_putstr_fd("ERROR: render_game(): game->sprites is NULL\n", 2);
		return (false);
	}
	else
		ft_putstr_fd("SUCCESS: render_game(): game->sprites -> ok\n", 2);


	if (mlx_image_to_window(game->mlx, game->sprites->player, 100, 100) == -1)
	{
		mlx_close_window(game->mlx);
		ft_putstr_fd("ERROR: mlx_image_to_window\n", 2);
		return(false);
	}
	else 
	{
		ft_putstr_fd("SUCCESS: render_game(): mlx_image_to_window -> ok\n", 2);  // test
	}
	return (true);
}



