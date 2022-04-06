/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:10:57 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/06 19:29:12 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_map *map, float move)
{
	int		i;
	int		u;

	u = 0;
	i = 0;
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
