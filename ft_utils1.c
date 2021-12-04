/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:30:25 by dzivanov          #+#    #+#             */
/*   Updated: 2021/07/15 02:09:16 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_error_printer(const char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

int	ft_extension_check(char *str, char *ext)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!str[i])
	{
		ft_error_printer("Wrong extension or path specified.");
		exit (EXIT_FAILURE);
	}
	while (str[i + j] && ext[j])
	{
		if (ft_to_upper(str[i + j]) == ft_to_upper(ext[j]))
			j++;
		else
			break ;
	}
	if (ext[j] == '\0' && str[i + j] == '\0')
		return (SUCCESS);
	ft_error_printer("Wrong extension or path specified.\n");
	exit (EXIT_FAILURE);
}

void	ft_map_validity(char **argv)
{
	int		fd;
	char	line[1];
	int		number_of_starts;
	int		number_of_exits;
	int		number_of_collectibles;

	number_of_starts = 0;
	number_of_exits = 0;
	number_of_collectibles = 0;
	fd = open(argv[1], O_RDONLY);
	ft_rectangular_check(argv[1]);
	ft_walls_checker(argv[1]);
	while (read(fd, line, 1) == 1)
	{
		if (line[0] != '1' && line[0] != '\n' && line[0] != 'C'
			&& line[0] != '0' && line[0] != 'E' && line[0] != 'P')
			ft_error_printer("Wrong characters used for the map\n");
		number_of_exits += (line[0] == 'E');
		number_of_collectibles += (line[0] == 'C');
		number_of_starts += (line[0] == 'P');
	}
	close(fd);
	ft_num_check(number_of_exits, number_of_collectibles, number_of_starts);
}

int	ft_to_upper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
