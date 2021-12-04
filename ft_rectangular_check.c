/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rectangular_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:35:53 by dzivanov          #+#    #+#             */
/*   Updated: 2021/07/15 03:04:48 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

/*
**	whatever - in the memory of 3 hours of our wasted lives on this bug
**	15.07.2021 03:04
*/

void	ft_rectangular_check(char *argv)
{
	int		fd;
	int		currentlength;
	int		currentline;
	char	tmp[1];
	int		whatever;

	fd = open(argv, O_RDONLY);
	currentline = 1;
	whatever = 1;
	while (whatever && (currentline <= ft_getnumberoflines(argv)))
	{
		whatever = read(fd, tmp, 1) == 1;
		if (currentline != 1 && tmp[0] != '\n' && whatever != 0)
			currentlength++;
		if (whatever == 0 || tmp[0] == '\n')
		{
			if (currentline != 1 && (currentlength != ft_getlinelength(argv)))
				ft_error_printer("Map is not rectangular\n");
			currentlength = 0;
			currentline++;
		}
	}
	close(fd);
}
