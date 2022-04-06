/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:18:23 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/06 18:44:15 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	in_window(t_point2d p1, t_point2d p2)
{
	if ((p1.x < 0 - (W_WIDTH / 2) && p2.x < 0 - (W_WIDTH / 2))
	 || (p1.y <  0 -(W_HEIGHT / 2) && p2.y < 0 - (W_HEIGHT / 2)))
		return (0);
	if ((p1.x > W_WIDTH - W_WIDTH / 2 && p2.x > W_WIDTH - W_WIDTH / 2)
	 || (p1.y > W_HEIGHT - W_HEIGHT / 2 && p2.y > W_HEIGHT - W_HEIGHT / 2))
		return (0);
	return (1);
}

void	draw_line(t_data img, t_point2d p1, t_point2d p2, t_point2d d)
{
	d.x = (p2.x - p1.x) * 2;
	d.y = (p2.y - p1.y) * 2;
	if (in_window(p1, p2))
	{
		if ((d.x > 0 && d.y > 0) || (d.x < 0 && d.y < 0))
		{
			if (ft_abs(d.x) >= ft_abs(d.y))
				bresenham1(img, p1, p2, d);
			else
				bresenham2(img, p1, p2, d);
		}
		else
		{
			if (ft_abs(d.x) <= ft_abs(d.y))
				bresenham3(img, p1, p2, d);
			else
				bresenham4(img, p1, p2, d);
		}
	}
}


void	draw_map(t_fdf *fdf)
{
	t_point2d	d;
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	while (y + 1 < fdf->map.max.y)
	{
		while (x + 1 < fdf->map.max.x) // (typed){int, int}
		{
			draw_line((*fdf).img, (t_point2d){fdf->map.map[y][x].x, 
			fdf->map.map[y][x].y}, (t_point2d){fdf->map.map[y][x + 1].x,
			 fdf->map.map[y][x + 1].y}, d);
			draw_line((*fdf).img, (t_point2d){fdf->map.map[y][x].x, 
			fdf->map.map[y][x].y}, (t_point2d){fdf->map.map[y + 1][x].x, 
			fdf->map.map[y + 1][x].y}, d);
			x++;
		}
		draw_line((*fdf).img, (t_point2d){fdf->map.map[y][x].x, 
		fdf->map.map[y][x].y}, (t_point2d){fdf->map.map[y + 1][x].x, 
		fdf->map.map[y + 1][x].y}, d);
		x = 0;
		y++;
	}
	x = 0;
	while (x + 1 < fdf->map.max.x)
	{
		draw_line((*fdf).img, (t_point2d){fdf->map.map[y][x].x, 
		fdf->map.map[y][x].y}, (t_point2d){fdf->map.map[y][x + 1].x, 
		fdf->map.map[y][x + 1].y}, d);
		x++;
	}
}
