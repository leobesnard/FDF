/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:27:28 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/09 01:49:05 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define W_WIDTH 1200
# define W_HEIGHT 800

# define INITIAL_X_SCALE 20
# define INITIAL_Y_SCALE 20
# define INITIAL_Z_SCALE 8

# define RIGHT 65363
# define DOWN 65364
# define LEFT 65361
# define UP 65362
# define ESC 65307
# define ROT_X 120
# define ROT_Y 121
# define ROT_Z 122
# define KEY_ZOOM '='
# define KEY_UNZOOM '-'
# define MOUSE_UP 5
# define UNZOOM 0.9
# define ZOOM 1.1

# define COLOR_MAX 0xcc0000
# define COLOR_MIN 0xffffff

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <fcntl.h>
#include <math.h>

#include "libft.h"

typedef struct	s_win {
	void	*mlx;
	void	*win;
}				t_win;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_point2d
{
	int		x;
	int		y;
}	t_point2d;

typedef struct s_map
{
	t_point		**map;
	t_point2d	max;
	int			z_min;
	int			z_max;
}	t_map;


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fdf
{
	char	*map_name;
	t_map	map;
	t_win	win;
	t_data	img;
}	t_fdf;

/* utils */

void			pixel_put(t_data *data, int x, int y, int color);
void			find_max_z(char **split, t_map *map);
void			ft_swap(t_point2d *a, t_point2d *b);
int				get_index(char *str, char c);
unsigned int	hex_to_unsigned(char *src);
int				get_size(char **tab);
int				ft_abs(int n);

/* bresenham */

void	bresenham1(t_data img, t_point2d p1, t_point2d p2, int z);
void	bresenham2(t_data img, t_point2d p1, t_point2d p2, int z);
void	bresenham3(t_data img, t_point2d p1, t_point2d p2, int z);
void	bresenham4(t_data img, t_point2d p1, t_point2d p2, int z);

/*colors*/

int		get_color(float z, char *split, t_map *map);
int		create_trgb(int t, int r, int g, int b);
int		mix_color(int c1, int c2, float f);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

/* parser */

int		parser(char *argv1, t_map *map);
int		get_map_size(char *argv1, t_map *map);

/*draw*/

void	draw_line(t_data img, t_point2d p1, t_point2d p2, int z);
void	draw_map(t_fdf *fdf);

/* free */

void	free_split(char **split);
void	free_map(t_map map);

/*movements*/

void	x_translation(t_map *map, float move);
void	y_translation(t_map *map, float move);
void	rot_z(t_map *map, float angle);
void	rot_y(t_map *map, float angle);
void	rot_x(t_map *map, float angle);
void	zoom(t_map *map, float move);

/*hook*/

int		mouse_hook(int keycode, t_fdf *fdf);
int		win_close2(int keycode, t_fdf *fdf);
int		key_hook(int keycode, t_fdf *fdf);
int		win_close1(t_fdf *fdf);

#endif
