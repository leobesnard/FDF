/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:22:30 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/06 14:33:49 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	x += W_WIDTH / 2;
	y += W_HEIGHT / 2;
	if (x > W_WIDTH -1 || x < 0 || y > W_HEIGHT - 1 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	get_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}
