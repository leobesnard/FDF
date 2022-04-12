/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:13:09 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/12 12:36:18 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_z(t_map *map, float angle)
{
	int		i;
	int		u;
	float	tmpx;
	float	tmpy;

	u = 0;
	i = 0;
	while (u < map->max.y)
	{
		while (i < map->max.x)
		{
			tmpx = map->map[u][i].x;
			tmpy = map->map[u][i].y;
			map->map[u][i].x = (tmpx * cos(angle)) - (tmpy * sin(angle));
			map->map[u][i].y = (tmpx * sin(angle)) + (tmpy * cos(angle));
			i++;
		}
		i = 0;
		u++;
	}
}

void	rot_x(t_map *map, float angle)
{
	int		i;
	int		u;
	float	tmpy;
	float	tmpz;

	u = 0;
	i = 0;
	while (u < map->max.y)
	{
		while (i < map->max.x)
		{
			tmpy = map->map[u][i].y;
			tmpz = map->map[u][i].z;
			map->map[u][i].y = (tmpy * cos(angle)) - (tmpz * sin(angle));
			map->map[u][i].z = (tmpy * sin(angle)) + (tmpz * cos(angle));
			i++;
		}
		i = 0;
		u++;
	}
}

void	rot_y(t_map *map, float angle)
{
	int		i;
	int		u;
	float	tmpx;
	float	tmpz;

	u = 0;
	i = 0;
	while (u < map->max.y)
	{
		while (i < map->max.x)
		{
			tmpx = map->map[u][i].x;
			tmpz = map->map[u][i].z;
			map->map[u][i].x = (tmpx * cos(angle)) + (tmpz * sin(angle));
			map->map[u][i].z = (tmpz * cos(angle)) - (tmpx * sin(angle));
			i++;
		}
		i = 0;
		u++;
	}
}

void	x_translation(t_map *map, float move)
{
	int		i;
	int		u;

	u = 0;
	i = 0;
	while (u < map->max.y)
	{
		while (i < map->max.x)
		{
			map->map[u][i].x += move;
			i++;
		}
		i = 0;
		u++;
	}
}

void	y_translation(t_map *map, float move)
{
	int		i;
	int		u;

	u = 0;
	i = 0;
	while (u < map->max.y)
	{
		while (i < map->max.x)
		{
			map->map[u][i].y += move;
			i++;
		}
		i = 0;
		u++;
	}
}
