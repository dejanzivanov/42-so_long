/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:30:25 by dzivanov          #+#    #+#             */
/*   Updated: 2021/07/15 00:33:37 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

static void	ft_free_map2d(t_game *game)
{
	int	i;

	i = game->map->lines;
	if (i < 0)
		return ;
	while (i >= 0)
	{
		if (game->map2d[i])
			free(game->map2d[i]);
		i--;
	}
	free(game->map2d);
}

static void	ft_free_list(t_list *lst)
{
	t_elem	*elem;
	t_elem	*next;

	elem = lst->first;
	while (elem)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
	free(lst);
}

void	ft_free_exit(t_game *game)
{
	if (!game)
		exit(EXIT_FAILURE);
	if (game->ptrs)
		free(game->ptrs);
	if (game->floor)
		free(game->floor);
	if (game->wall)
		free(game->wall);
	if (game->img)
		free(game->img);
	if (game->map2d)
		ft_free_map2d(game);
	if (game->map)
		free(game->map);
	if (game->exit)
		ft_free_list(game->exit);
	if (game->coll)
		ft_free_list(game->coll);
	if (game->player)
		free(game->player);
	if (game)
		free(game);
	exit(SUCCESS);
}

int	ft_close_clean(t_game *game)
{
	if (game->player->img.img_ptr)
		mlx_destroy_image(game->ptrs->mlx, game->player->img.img_ptr);
	if (game->exit->img.img_ptr)
		mlx_destroy_image(game->ptrs->mlx, game->exit->img.img_ptr);
	if (game->coll->img.img_ptr)
		mlx_destroy_image(game->ptrs->mlx, game->coll->img.img_ptr);
	if (game->floor->img_ptr)
		mlx_destroy_image(game->ptrs->mlx, game->floor->img_ptr);
	if (game->wall->img_ptr)
		mlx_destroy_image(game->ptrs->mlx, game->wall->img_ptr);
	if (game->img->img_ptr)
		mlx_destroy_image(game->ptrs->mlx, game->img->img_ptr);
	if (game->ptrs->win)
		mlx_destroy_window(game->ptrs->mlx, game->ptrs->win);
	if (game->ptrs->mlx)
		mlx_destroy_display(game->ptrs->mlx);
	if (game->ptrs->mlx)
		free(game->ptrs->mlx);
	ft_free_exit(game);
	exit(EXIT_FAILURE);
	return (1);
}

void	ft_putstr_fd(const char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}
