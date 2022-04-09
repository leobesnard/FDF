/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:54:24 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/08 18:22:55 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <stdio.h>


void	bresenham1(t_data img, t_point2d p1, t_point2d p2, int color)
{
	t_point2d	d;
	int			e;

	if (p1.x > p2.x)
		ft_swap(&p1, &p2);
	d.y = (p2.y - p1.y) * 2;
	d.x = (p2.x - p1.x) * 2;
	e = p2.x - p1.x;
	while (p1.x <= p2.x)
	{
		pixel_put(&img, p1.x, p1.y, color);
		p1.x++;
		e -= d.y;
		if (e <= 0)
		{
			p1.y++;
			e += d.x;
		}
	}
}

void	bresenham2(t_data img, t_point2d p1, t_point2d p2, int color)
{
	t_point2d	d;
	int			e;

	if (p1.x > p2.x)
		ft_swap(&p1, &p2);
	d.y = (p2.y - p1.y) * 2;
	d.x = (p2.x - p1.x) * 2;
	e = p2.y - p1.y;
	while (p1.y <= p2.y)
	{
		pixel_put(&img, p1.x, p1.y, color);
		p1.y++;
		e -= d.x;
		if (e <= 0)
		{
			p1.x++;
			e += d.y;
		}
	}
}

void	bresenham3(t_data img, t_point2d p1, t_point2d p2, int color)
{
	t_point2d	d;
	int			e;

	if (p1.y > p2.y)
		ft_swap(&p1, &p2);
	d.y = (p2.y - p1.y) * 2;
	d.x = (p2.x - p1.x) * 2;
	e = p2.y - p1.y;
	while (p1.y <= p2.y)
	{
		pixel_put(&img, p1.x, p1.y, color);
		p1.y++;
		e += d.x;
		if (e <= 0)
		{
			p1.x--;
			e += d.y;
		}
	}
}

void	bresenham4(t_data img, t_point2d p1, t_point2d p2, int color)
{
	t_point2d	d;
	int			e;

	if (p1.x > p2.x)
		ft_swap(&p1, &p2);
	d.y = (p2.y - p1.y) * 2;
	d.x = (p2.x - p1.x) * 2;
	e = p2.x - p1.x;
	while(p1.x <= p2.x)
	{
		pixel_put(&img, p1.x, p1.y, color);
		p1.x++;
		e += d.y;
		if (e <= 0)
		{
			p1.y--;
			e += d.x;
		}
	}
}

