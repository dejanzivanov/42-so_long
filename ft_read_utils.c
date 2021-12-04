/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:30:40 by dzivanov          #+#    #+#             */
/*   Updated: 2021/07/14 13:54:45 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map_data(char *argv, t_map *map)
{
	char	tmp[1];
	int		fd;

	fd = open(argv, O_RDONLY);
	map->lines = 1;
	map->linelength = 0;
	while (read(fd, tmp, 1) == 1)
	{
		if (tmp[0] != '\n' && map->lines == 1)
			map->linelength++;
		else if (tmp[0] == '\n')
			map->lines++;
	}
	close(fd);
}

void	ft_get_2d_map_data(char *argv, t_game *game)
{
	char	tmp[1];
	int		cline;
	int		ccoll;
	int		fd;

	cline = 0;
	ccoll = 0;
	fd = open(argv, O_RDONLY);
	game->map2d[cline] = (char *)malloc(game->map->linelength + 1);
	while (read(fd, tmp, 1) == 1)
	{
		if (tmp[0] == '\n')
		{
			game->map2d[cline++][ccoll] = '\0';
			game->map2d[cline] = (char *)malloc(game->map->linelength + 1);
			ccoll = 0;
		}
		else if (tmp[0] != '\n')
			game->map2d[cline][ccoll] = tmp[0];
		if (tmp[0] != '\n')
			ccoll++;
	}
	game->map2d[cline][ccoll] = '\0';
	game->map2d[cline + 1] = '\0';
	close(fd);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}
