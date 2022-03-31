/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:27:28 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/31 20:07:59 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define W_WIDTH 1920
# define W_HEIGHT 1080

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_diff
{
	int	x;
	int	y;
}	t_diff;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	draw_line(t_data img, t_point p1, t_point p2, t_diff d);
void	bresenham1(t_data img, t_point p1, t_point p2, t_diff d);
void	bresenham2(t_data img, t_point p1, t_point p2, t_diff d);
void	bresenham3(t_data img, t_point p1, t_point p2, t_diff d);
void	bresenham4(t_data img, t_point p1, t_point p2, t_diff d);
void	pixel_put(t_data *data, int x, int y, int color);
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);
void	ft_swap(int *a, int *b);
int	ft_abs(int n);

#endif
