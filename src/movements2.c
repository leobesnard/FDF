/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:10:57 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/11 17:50:06 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_map *map, float move)
{
	int		i;
	int		u;

	u = 0;
	i = 0;
	if (move > 1 && map->map[u][i].x >= 700)
		return ;
	while (u < map->max.y)
	{
		while(i < map->max.x)
		{
			map->map[u][i].x *= move;
			map->map[u][i].y *= move;
			map->map[u][i].z *= move;
			i++;
		}
		i = 0;
		u++;
	}
}

void	iso_view(t_fdf *fdf)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while (y < fdf->map.max.y)
	{
		while (x < fdf->map.max.x)
		{
			fdf->map.map[y][x].x = fdf->initial_map_cpy.map[y][x].x;
			fdf->map.map[y][x].y = fdf->initial_map_cpy.map[y][x].y;
			fdf->map.map[y][x].z = fdf->initial_map_cpy.map[y][x].z;
			x++;
		}
		x = 0;
		y++;
	}
	initial_scale(fdf);
	rot_z(&fdf->map, 0.7);
}

void	para_view(t_fdf *fdf)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while (y < fdf->map.max.y)
	{
		while (x < fdf->map.max.x)
		{
			fdf->map.map[y][x].x = fdf->initial_map_cpy.map[y][x].x;
			fdf->map.map[y][x].y = fdf->initial_map_cpy.map[y][x].y;
			fdf->map.map[y][x].z = fdf->initial_map_cpy.map[y][x].z;
			x++;
		}
		x = 0;
		y++;
	}
	initial_scale(fdf);
	rot_y(&fdf->map, 0.5);
}
