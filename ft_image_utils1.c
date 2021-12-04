/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 02:22:35 by dzivanov          #+#    #+#             */
/*   Updated: 2021/11/05 15:11:36 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	print_moves(t_game *game)
{
	game->move = ft_itoa(game->moves);
	mlx_string_put(game->ptrs->mlx, game->ptrs->win, 30, 30, 123456,
		game->move);
	free(game->move);
}

void	ft_draw_cheese(t_game *game)
{
	int		i;
	int		j;
	t_elem	*elem;

	i = 0;
	while (game->map2d[i])
	{
		j = 0;
		while (game->map2d[i][j])
		{
			if (game->map2d[i][j] == 'C')
			{
				elem = ft_get_collectible(game, i, j);
				if (elem && elem->visited == false)
					ft_draw_on_img(game->img, &game->coll->img,
						j * SIZE, i * SIZE);
			}
			else if (game->map2d[i][j] == 'E')
				ft_draw_on_img(game->img, &game->exit->img,
					j * SIZE, i * SIZE);
			j++;
		}
		i++;
	}
	print_moves(game);
}

void	ft_draw_player(t_game *game)
{
	game->player->smooth_x += (game->player->x - game->player->smooth_x) * 0.5;
	game->player->smooth_y += (game->player->y - game->player->smooth_y) * 0.5;
	ft_draw_on_img(game->img, &game->player->img,
		(int)(game->player->smooth_y * SIZE),
		(int)(game->player->smooth_x * SIZE));
	print_moves(game);
}

void	ft_draw_ice(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map2d[i])
	{
		j = 0;
		while (game->map2d[i][j])
		{
			if (game->map2d[i][j] == '1')
				ft_draw_on_img(game->img, game->wall, j * SIZE, i * SIZE);
			else
				ft_draw_on_img(game->img, game->floor, j * SIZE, i * SIZE);
			j++;
		}
		i++;
	}
	print_moves(game);
}
