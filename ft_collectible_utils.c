/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectible_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:25:38 by dzivanov          #+#    #+#             */
/*   Updated: 2021/07/14 13:50:54 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_elem	*ft_get_collectible(t_game *game, int i, int j)
{
	t_elem	*elem;

	elem = game->coll->first;
	while (elem)
	{
		if (elem->x == i && elem->y == j)
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}

bool	ft_is_collectible(t_game *game, int i, int j)
{
	t_elem	*elem;

	elem = game->coll->first;
	while (elem)
	{
		if (elem->x == i && elem->y == j)
			return (true);
		elem = elem->next;
	}
	return (false);
}

void	ft_set_to_visited(t_game *game)
{
	t_elem	*elem;

	elem = game->coll->first;
	while (elem)
	{
		if (elem->x == game->player->x && elem->y == game->player->y)
		{
			elem->visited = true;
			return ;
		}
		elem = elem->next;
	}
}

static int	ft_lstlength(t_list *lst)
{
	int		length;
	t_elem	*elem;

	if (!lst)
		return (0);
	length = 0;
	elem = lst->first;
	while (elem)
	{
		length++;
		elem = elem->next;
	}
	return (length);
}

bool	ft_all_coll_picked(t_game *game)
{
	t_elem	*elem;
	int		length;
	int		count;

	count = 0;
	length = ft_lstlength(game->coll);
	elem = game->coll->first;
	while (elem)
	{
		if (elem->visited)
			count++;
		elem = elem->next;
	}
	if (count == length)
		return (true);
	return (false);
}
