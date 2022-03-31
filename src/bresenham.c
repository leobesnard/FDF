/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:54:24 by lbesnard          #+#    #+#             */
/*   Updated: 2022/03/31 21:16:01 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <stdio.h>

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > W_WIDTH || x < 0 || y > W_HEIGHT || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_data img, t_point p1, t_point p2, t_diff d)
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

void	bresenham1(t_data img, t_point p1, t_point p2, t_diff d)
{
	int	e;

	if (p1.x > p2.x)
	{
		ft_swap(&p1.x, &p2.x);
		ft_swap(&p1.y, &p2.y);
	}
	d.y = (p2.y - p1.y) * 2;
	d.x = (p2.x - p1.x) * 2;
	e = p2.x - p1.x;
	while (p1.x <= p2.x)
	{
		pixel_put(&img, p1.x, p1.y, 0xff0000);
		p1.x++;
		e -= d.y;
		if (e <= 0)
		{
			p1.y++;
			e += d.x;
		}
	}
}

void	bresenham2(t_data img, t_point p1, t_point p2, t_diff d)
{
	int	e;

	if (p1.x > p2.x)
	{
		ft_swap(&p1.x, &p2.x);
		ft_swap(&p1.y, &p2.y);
	}
	d.y = (p2.y - p1.y) * 2;
	d.x = (p2.x - p1.x) * 2;
	e = p2.y - p1.y;
	while (p1.y <= p2.y)
	{
		pixel_put(&img, p1.x, p1.y, 0xff0000);
		p1.y++;
		e -= d.x;
		if (e <= 0)
		{
			p1.x++;
			e += d.y;
		}
	}
}

void	bresenham3(t_data img, t_point p1, t_point p2, t_diff d)
{
	int	e;

	if (p1.x < p2.x)
	{
		ft_swap(&p1.x, &p2.x);
		ft_swap(&p1.y, &p2.y);
	}
	d.y = (p2.y - p1.y) * 2;
	d.x = (p2.x - p1.x) * 2;
	e = p2.y - p1.y;
	while (p1.y <= p2.y)
	{
		pixel_put(&img, p1.x, p1.y, 0xff0000);
		p1.y++;
		e -= d.x;
		if (e >= 0)
		{
			p1.x--;
			e -= d.y;
		}
	}
}

void	bresenham4(t_data img, t_point p1, t_point p2, t_diff d)
{
	int	e;

	if (p1.x > p2.x)
	{
		ft_swap(&p1.x, &p2.x);
		ft_swap(&p1.y, &p2.y);
	}
	d.y = (p2.y - p1.y) * 2;
	d.x = (p2.x - p1.x) * 2;
	e = p2.x - p1.x;
	while(p1.x <= p2.x)
	{
		pixel_put(&img, p1.x, p1.y, 0xff0000);
		p1.x++;
		e += d.y;
		if (e <= 0)
		{
			p1.y--;
			e += d.x;
		}
	}
}
