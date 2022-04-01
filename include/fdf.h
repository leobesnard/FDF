/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:27:28 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/01 19:36:01 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define W_WIDTH 1920
# define W_HEIGHT 1080

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <fcntl.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	pixel_put(t_data *data, int x, int y, int color);
void	ft_swap(int *a, int *b);
int		ft_abs(int n);

#endif
