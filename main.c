/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:20:25 by dzivanov          #+#    #+#             */
/*   Updated: 2021/07/15 01:31:21 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

/*
**	gcc main.c game.c ft_utils1.c ft_utils2.c ft_utils3.c  ft_free_utils.c
**	ft_read_utils.c ft_player_movement.c ft_collectible_utils.c
**	ft_image_utils.c ft_image_utils1.c mlx/libmlx_Linux.a -L
**	/usr/include/X11/extensions/ -lXext -lX11 && ./a.out maps/valid1.ber
**
*/

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		ft_extension_check(argv[1], ".ber");
		ft_map_validity(argv);
		game = ft_init_game();
		ft_read_map_data(argv[1], game->map);
		game->map2d = (char **)malloc(sizeof(char *) * (game->map->lines + 1));
		if (!game->map2d)
			ft_free_exit(game);
		ft_rectangular_check(argv[1]);
		ft_walls_checker(argv[1]);
		ft_get_2d_map_data(argv[1], game);
		ft_set_positions(game);
		ft_start_game(game);
	}
	else
		ft_error_printer("Wrong number of arguments");
	return (0);
}
