/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 23:40:13 by dzivanov          #+#    #+#             */
/*   Updated: 2021/11/08 22:24:59 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

static void	ft_load_image(t_game *game, t_img *img, void *mlx, char *path)
{
	img->img_ptr = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->img_ptr)
	{
		ft_putstr_fd("Error\nWhile loading images\n", 2);
		ft_free_exit(game);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->linelength, &img->endian);
}

void	ft_load_multiple_images(t_game *game)
{
	ft_load_image(game, &game->player->img, game->ptrs->mlx, PLAYERPATH);
	ft_load_image(game, game->wall, game->ptrs->mlx, WALLPATH);
	ft_load_image(game, game->floor, game->ptrs->mlx, FLOORPATH);
	ft_load_image(game, &game->coll->img, game->ptrs->mlx, COLLPATH);
	ft_load_image(game, &game->exit->img, game->ptrs->mlx, EXITPATH);
}

static int	ft_get_pixel(t_img *img, int x, int y)
{
	return (*(int *)(img->addr + y * img->linelength + x
		* img->bits_per_pixel / 8));
}

static void	ft_set_pixel(t_img *img, int x, int y, int color)
{
	*(unsigned int *)(img->addr + y * img->linelength + x * img->bits_per_pixel / 8) = color;
}

void	ft_draw_on_img(t_img *img, t_img *upp_img, int startx, int starty)
{
	t_draw	draw;

	draw.x = 0;
	while (draw.x < SIZE)
	{
		draw.y = 0;
		while (draw.y < SIZE)
		{
			draw.r_x = (float)draw.x / (float)SIZE;
			draw.r_y = (float)draw.y / (float)SIZE;
			draw.pos_x = draw.r_x * upp_img->width;
			draw.pos_y = draw.r_y * upp_img->height;
			draw.color = ft_get_pixel(upp_img, draw.pos_x, draw.pos_y);
			draw.p_data_x = startx + draw.x;
			draw.p_data_y = starty + draw.y;
			if (draw.color != (int)BLACK)
				ft_set_pixel(img, draw.p_data_x, draw.p_data_y, draw.color);
			draw.y++;
		}
		draw.x++;
	}
}
