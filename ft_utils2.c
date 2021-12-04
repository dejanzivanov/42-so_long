/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:35:25 by dzivanov          #+#    #+#             */
/*   Updated: 2021/07/19 23:11:30 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
**	num1 - number of exits
**	num2 - number of coolectibles
**	num3 - number of starts
*/

void	ft_num_check(int num1, int num2, int num3)
{
	if (num1 == 0 || num2 == 0 || num3 != 1)
	{
		ft_error_printer("Wrong number of input parameters\n");
	}
}

void	ft_lst_addback(t_game *game, t_list *list, int x, int y)
{
	t_elem	*elem;
	t_elem	*temp;

	elem = (t_elem *)malloc(sizeof(t_elem));
	if (!elem)
	{
		ft_free_exit(game);
	}
	elem->x = x;
	elem->y = y;
	elem->visited = false;
	if (!list->first)
	{
		elem->next = NULL;
		list->first = elem;
		return ;
	}
	temp = list->first;
	while (temp->next)
		temp = temp->next;
	temp->next = elem;
	elem->next = NULL;
}

void	ft_set_positions(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->lines)
	{
		j = 0;
		while (game->map2d[i][j])
		{
			if (game->map2d[i][j] == 'C')
				ft_lst_addback(game, game->coll, i, j);
			if (game->map2d[i][j] == 'E')
				ft_lst_addback(game, game->exit, i, j);
			if (game->map2d[i][j] == 'P')
			{
				game->player->x = i;
				game->player->y = j;
				game->player->smooth_x = i;
				game->player->smooth_y = j;
			}
			j++;
		}
		i++;
	}
}

bool	ft_is_exit(t_game *game, int i, int j)
{
	t_elem	*elem;

	elem = game->exit->first;
	while (elem)
	{
		if (elem->x == i && elem->y == j)
			return (true);
		elem = elem->next;
	}
	return (false);
}
