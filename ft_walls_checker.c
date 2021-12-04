/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 22:20:46 by dzivanov          #+#    #+#             */
/*   Updated: 2021/07/15 02:30:08 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

int	ft_getnumberoflines(char *pathofmap)
{
	int		lines;
	char	tmp[1];
	int		fd;

	fd = open(pathofmap, O_RDONLY);
	lines = 1;
	while (read(fd, tmp, 1) == 1)
	{
		if (tmp[0] == '\n')
			lines++;
	}
	close(fd);
	return (lines);
}

int	ft_getlinelength(char *pathofmap)
{
	int		fd;
	int		length;
	char	tmp[1];
	int		readreturn;

	length = 0;
	fd = open(pathofmap, O_RDONLY);
	while (1)
	{
		readreturn = read(fd, tmp, 1);
		if (readreturn == 1 && tmp[0] != '\n')
			length++;
		else if (tmp[0] == '\n' || readreturn == 0)
			break ;
	}
	return (length);
}

void	ft_walls_checker(char *argv)
{
	int		nboflines;
	int		line;
	char	tmp[1];
	int		fd;
	int		linelengths[2];

	linelengths[0] = ft_getlinelength(argv);
	linelengths[1] = 0;
	nboflines = ft_getnumberoflines(argv);
	fd = open(argv, O_RDONLY);
	line = 1;
	while (read(fd, tmp, 1) == 1)
	{
		if (tmp[0] != '1' && tmp[0] != '\n' && (line == 1 || line == nboflines))
			ft_error_printer("Map is not surrounded by walls\n");
		else if ((linelengths[1]++ == 0 || linelengths[1] == linelengths[0])
			&& tmp[0] != '1')
			ft_error_printer("Map is not surrounded by walls\n");
		else if (tmp[0] == '\n')
		{
			line++;
			linelengths[1] = 0;
		}
	}
	close(fd);
}
