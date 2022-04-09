/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:37:59 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/09 00:29:24 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	hex_to_unsigned(char *src)
{
	char			*base;
	char			*str;
	unsigned long	ret;
	int				i;
	int				j;
	
	i = 0;
	j = 0;
	ret = 0;
	str = &src[2];
	base = "0123456789ABCDEFabcdef";
	while(str[i] && ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
	|| (str[i] >= 'A' && str[i] <= 'F')))
	{
		while (base[j] && base[j] != str[i])
			j++;
		if (j > 15)
			j -= 6;
		ret = ret * 16 + j;
		i++;
		j = 0;
	}
	return (ret);
}

void	find_max_z(char **split, t_map *map)
{
	int	n;
	int	i;
	
	i = 0;
	while (split[i])
	{
		n = atoi(split[i]);
		if (n > map->z_max)
			map->z_max = n;
		if (n < map->z_min)
			map->z_min = n;
		i++;
	}
}
