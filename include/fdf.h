/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:27:28 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/06 00:19:22 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define W_WIDTH 1920
# define W_HEIGHT 1080

# define INITIAL_X_SCALE 20
# define INITIAL_Y_SCALE 20
# define INITIAL_Z_SCALE 5

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <fcntl.h>
#include "libft.h"

typedef struct	s_win {
	void	*mlx;
	void	*win;
}				t_win;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_map
{
	t_point	**map;
	t_point	max;
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

/*utils*/

void	pixel_put(t_data *data, int x, int y, int color);
void	ft_swap(int *a, int *b);
int		get_size(char **tab);
int		ft_abs(int n);

/*bresenham*/

void	bresenham1(t_data img, t_point p1, t_point p2, t_point d);
void	bresenham2(t_data img, t_point p1, t_point p2, t_point d);
void	bresenham3(t_data img, t_point p1, t_point p2, t_point d);
void	bresenham4(t_data img, t_point p1, t_point p2, t_point d);

/*colors*/

int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

/*parser*/

int	parser(char *argv1, t_map *map);
int	get_map_size(char *argv1, t_map *map);

/*draw*/

void	draw_line(t_data img, t_point p1, t_point p2, t_point d);
int		draw_map(t_fdf *fdf);

#endif
