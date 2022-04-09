/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:24:24 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/09 03:08:00 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color(float z, char *split, t_map *map)
{
	char	*index;
	int		max;
	int		min;
	
	index = ft_strchr(split, ',');
	(void)map;
	if (index)
	{
		 return (hex_to_unsigned(index + 1));//TODO: remplacer par hex to unsigned int
	}
	else
	{
		max = map->z_max * INITIAL_Z_SCALE;
		min = map->z_min * INITIAL_Z_SCALE;
		if (z > 0 && z <= max)
			return (mix_color(0x630606, 0xB4846C, z / max));
		else if (z == 0)
			return (0x2D4059);
		else
			return (mix_color(0x1E2022, 0x15408f, z / min));
	}
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
