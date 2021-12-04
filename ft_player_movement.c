/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:39:40 by dzivanov          #+#    #+#             */
/*   Updated: 2021/07/14 16:01:44 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	ft_move_player_up(t_game *game)
{
	game->player->x -= 1;
	game->moves++;
	print_moves(game);
}

void	ft_move_player_left(t_game *game)
{
	game->player->y -= 1;
	game->moves++;
	print_moves(game);
}

void	ft_move_player_down(t_game *game)
{
	game->player->x += 1;
	game->moves++;
	print_moves(game);
}

void	ft_move_player_right(t_game *game)
{
	game->player->y += 1;
	game->moves++;
	print_moves(game);
}

void	ft_output_player_moves(t_game *game)
{
	ft_putnbr(game->moves);
	ft_putstr_fd("\n", 1);
}
