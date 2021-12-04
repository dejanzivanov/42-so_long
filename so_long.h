/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:59:45 by dzivanov          #+#    #+#             */
/*   Updated: 2021/11/07 19:14:44 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ERROR -1
# define DONE 0
# define SUCCESS 1
# define SIZE 80
# define W 119
# define A 97
# define D 100
# define S 115
# define ESC 65307
# define BLACK 0xFF000000
# define PLAYERPATH "images/jerry.xpm"
# define FLOORPATH "images/ice.xpm"
# define EXITPATH "images/exit.xpm"
# define COLLPATH "images/cheese.xpm"
# define WALLPATH "images/wall.xpm"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include "mlx/mlx.h"

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		linelength;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_ptrs
{
	void	*mlx;
	void	*win;
}			t_ptrs;

typedef struct s_map
{
	int	lines;
	int	linelength;
}		t_map;

typedef struct s_player
{
	t_img	img;
	int		x;
	int		y;
	float	smooth_x;
	float	smooth_y;
}			t_player;

typedef struct s_elem
{
	int				x;
	int				y;
	bool			visited;
	struct s_elem	*next;
}					t_elem;

typedef struct s_list
{
	t_elem	*first;
	t_img	img;
}			t_list;

typedef struct s_draw
{
	int		x;
	int		y;
	float	r_x;
	float	r_y;
	int		color;
	int		pos_x;
	int		pos_y;
	int		p_data_x;
	int		p_data_y;
}				t_draw;

typedef struct s_game
{
	t_player		*player;
	t_list			*coll;
	t_list			*exit;
	t_img			*img;
	t_img			*floor;
	t_img			*wall;
	t_ptrs			*ptrs;
	t_map			*map;
	char			**map2d;
	int				moves;
	char			*move;
}					t_game;

int		ft_getnumberoflines(char *argv);
int		ft_getlinelength(char *argv);
void	print_moves(t_game *game);
char	*ft_itoa(int n);
void	ft_error_printer(const char *msg);
int		ft_strlen(const char *s);
int		ft_strlen(const char *s);
int		ft_extension_check(char *str, char *ext);
void	ft_map_validity(char **argv);
void	ft_num_check(int num1, int num2, int num3);
t_game	*ft_init_game(void);
int		ft_to_upper(int c);
void	ft_read_map_data(char *argv, t_map *map);
void	ft_walls_checker(char *argv);
void	ft_rectangular_check(char *argv);
void	ft_free_exit(t_game *game);
void	ft_get_2d_map_data(char *argv, t_game *game);
void	ft_set_positions(t_game *game);
void	ft_lst_addback(t_game *game, t_list *list, int x, int y);
void	ft_start_game(t_game *game);
int		ft_close_clean(t_game *game);
void	ft_putchar(char c);
void	ft_putstr_fd(const char *str, int fd);
void	ft_putnbr(int nb);
void	ft_move_player_up(t_game *game);
void	ft_move_player_left(t_game *game);
void	ft_move_player_down(t_game *game);
void	ft_move_player_right(t_game *game);
void	ft_output_player_moves(t_game *game);
void	ft_load_multiple_images(t_game *game);
void	ft_draw_ice(t_game *game);
void	ft_draw_cheese(t_game *game);
void	ft_set_to_visited(t_game *game);
bool	ft_is_collectible(t_game *game, int i, int j);
bool	ft_is_exit(t_game *game, int i, int j);
t_elem	*ft_get_collectible(t_game *game, int i, int j);
void	ft_draw_player(t_game *game);
void	ft_draw_on_img(t_img *img, t_img *upp_img, int startx, int starty);
bool	ft_all_coll_picked(t_game *game);

#endif