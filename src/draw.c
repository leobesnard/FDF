/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:18:23 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/06 00:17:21 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_data img, t_point p1, t_point p2, t_point d)
{
	d.x = (p2.x - p1.x) * 2;
	d.y = (p2.y - p1.y) * 2;
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


int draw_map(t_fdf *fdf)
{
	t_point	d;
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	while (y + 1 < fdf->map.max.y)
	{
		while (x + 1 < fdf->map.max.x)
		{
			draw_line((*fdf).img, fdf->map.map[y][x], fdf->map.map[y][x + 1], d);
			draw_line((*fdf).img, fdf->map.map[y][x], fdf->map.map[y + 1][x], d);
			x++;
		}
		draw_line((*fdf).img, fdf->map.map[y][x], fdf->map.map[y + 1][x], d);
		x = 0;
		y++;
	}
	x = 0;
	while (x + 1 < fdf->map.max.x)
	{
		draw_line((*fdf).img, fdf->map.map[y][x], fdf->map.map[y][x + 1], d);
		x++;
	}
	return (1);
}
