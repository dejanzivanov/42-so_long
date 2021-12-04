/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:21:15 by dzivanov          #+#    #+#             */
/*   Updated: 2021/07/14 23:20:20 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

int	ft_keyhook(int key, t_game *game)
{
	if (game->map2d[game->player->x - 1][game->player->y] != '1' && key == W)
		ft_move_player_up(game);
	if (game->map2d[game->player->x][game->player->y - 1] != '1' && key == A)
		ft_move_player_left(game);
	if (game->map2d[game->player->x + 1][game->player->y] != '1' && key == S)
		ft_move_player_down(game);
	if (game->map2d[game->player->x][game->player->y + 1] != '1' && key == D)
		ft_move_player_right(game);
	if (key == ESC)
		ft_close_clean(game);
	if (ft_is_collectible(game, game->player->x, game->player->y))
		ft_set_to_visited(game);
	if (ft_is_exit(game, game->player->x, game->player->y)
		&& ft_all_coll_picked(game))
		ft_close_clean(game);
	return (1);
}

int	close_window(t_game *game)
{
	ft_close_clean(game);
	exit(SUCCESS);
}

int	ft_render_next_frame(t_game *game)
{
	mlx_put_image_to_window(game->ptrs->mlx, game->ptrs->win,
		game->img->img_ptr, 0, 0);
	ft_draw_ice(game);
	ft_draw_cheese(game);
	ft_draw_player(game);
	print_moves(game);
	return (1);
}

void	ft_start_game(t_game *game)
{
	game->ptrs->mlx = mlx_init();
	game->ptrs->win = mlx_new_window(game->ptrs->mlx,
			game->map->linelength * SIZE, game->map->lines * SIZE, "So_long");
	game->img->img_ptr = mlx_new_image(game->ptrs->mlx,
			game->map->linelength * SIZE,
			game->map->lines * SIZE);
	game->img->addr = mlx_get_data_addr(game->img->img_ptr,
			&game->img->bits_per_pixel,
			&game->img->linelength, &game->img->endian);
	ft_load_multiple_images(game);
	mlx_loop_hook(game->ptrs->mlx, ft_render_next_frame, game);
	mlx_key_hook(game->ptrs->win, ft_keyhook, game);
	mlx_hook(game->ptrs->win, 33, (1L << 17), close_window, game);
	mlx_loop(game->ptrs->mlx);
	print_moves(game);
}
