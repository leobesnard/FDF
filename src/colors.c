/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:24:24 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/08 00:37:25 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color(float z, char * split)
{
	int	r;
	int	g;
	int	b;
	char	*index;
	
	r = 0;
	g = 0;
	b = 0;
	index = ft_strchr(split, ',');
	if (index)
		 return (ft_atoi(index + 1));//TODO: remplacer par hex to unsigned int
	else
	{
		z *= 10;
		return (0xff0000);
	}
	/* printf("%d\n", create_trgb(0, 255, 255, 0));
	printf("%d\n", create_trgb(0, 0, 0, 255)); */
	return (create_trgb(0, r, g ,b));
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
