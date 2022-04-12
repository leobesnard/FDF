/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:18:23 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/12 12:52:31 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	in_window(t_point2d p1, t_point2d p2)
{
	if ((p1.x < 0 - (W_WIDTH / 2) && p2.x < 0 - (W_WIDTH / 2))
		|| (p1.y < 0 -(W_HEIGHT / 2) && p2.y < 0 - (W_HEIGHT / 2)))
		return (0);
	if ((p1.x > W_WIDTH - W_WIDTH / 2 && p2.x > W_WIDTH - W_WIDTH / 2)
		|| (p1.y > W_HEIGHT - W_HEIGHT / 2 && p2.y > W_HEIGHT - W_HEIGHT / 2))
		return (0);
	return (1);
}

void	draw_line(t_data img, t_point2d p1, t_point2d p2, int color)
{
	t_point2d	d;

	d.x = (p2.x - p1.x) * 2;
	d.y = (p2.y - p1.y) * 2;
	if (in_window(p1, p2))
	{
		if ((d.x > 0 && d.y > 0) || (d.x < 0 && d.y < 0))
		{
			if (ft_abs(d.x) >= ft_abs(d.y))
				bresenham1(img, p1, p2, color);
			else
				bresenham2(img, p1, p2, color);
		}
		else
		{
			if (ft_abs(d.x) <= ft_abs(d.y))
				bresenham3(img, p1, p2, color);
			else
				bresenham4(img, p1, p2, color);
		}
	}
}

void	draw_map(t_fdf *fdf)
{
	int		x;
	int		y;

	y = -1;
	while (++y < fdf->map.max.y)
	{
		x = -1;
		while (++x < fdf->map.max.x)
		{
			if (x != fdf->map.max.x - 1)
			{
				draw_line((*fdf).img, (t_point2d){fdf->map.map[y][x].x,
					fdf->map.map[y][x].y}, (t_point2d){fdf->map.map[y][x + 1].x,
					fdf->map.map[y][x + 1].y}, (mix_color(fdf->map.map[y][x].c,
							fdf->map.map[y][x + 1].c, 0.5)));
			}
			if (y != fdf->map.max.y - 1)
			{
				draw_line((*fdf).img, (t_point2d){fdf->map.map[y][x].x,
					fdf->map.map[y][x].y}, (t_point2d){fdf->map.map[y + 1][x].x,
					fdf->map.map[y + 1][x].y}, (mix_color(fdf->map.map[y][x].c,
							fdf->map.map[y + 1][x].c, 0.5)));
			}
		}
	}
}
