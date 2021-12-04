/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:50:25 by dzivanov          #+#    #+#             */
/*   Updated: 2021/07/15 00:40:27 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_initialise_pointers(t_game *game)
{
	game->ptrs->mlx = NULL;
	game->ptrs->win = NULL;
}

static void	ft_initialise_player(t_game *game)
{
	game->player->x = 0;
	game->player->y = 0;
	game->player->smooth_x = 0;
	game->player->smooth_y = 0;
}

static void	ft_initialise_map(t_game *game)
{
	game->map->linelength = 0;
	game->map->lines = -1;
}

static void	ft_initialise_images(t_game *game)
{
	game->img->img_ptr = NULL;
	game->img->addr = NULL;
	game->img->bits_per_pixel = 0;
	game->img->linelength = 0;
	game->img->endian = 0;
	game->img->width = 0;
	game->img->height = 0;
}

t_game	*ft_init_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->player = (t_player *)malloc(sizeof(t_player));
	game->coll = (t_list *)malloc(sizeof(t_list));
	game->coll->first = NULL;
	game->exit = (t_list *)malloc(sizeof(t_list));
	game->exit->first = NULL;
	game->map = (t_map *)malloc(sizeof(t_map));
	game->map2d = NULL;
	game->img = (t_img *)malloc(sizeof(t_img));
	game->ptrs = (t_ptrs *)malloc(sizeof(t_img));
	game->floor = (t_img *)malloc(sizeof(t_img));
	game->wall = (t_img *)malloc(sizeof(t_img));
	game->moves = 0;
	if (!game || !game->player || !game->coll || !game->exit || !game->map
		|| !game->img || !game->ptrs || !game->wall || !game->floor)
		ft_free_exit(game);
	ft_initialise_player(game);
	ft_initialise_map(game);
	ft_initialise_images(game);
	ft_initialise_pointers(game);
	return (game);
}
