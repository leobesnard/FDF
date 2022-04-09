/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:36:49 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/09 01:49:52 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mix_color(int c1, int c2, float f)
{
	return (create_trgb(0, (get_r(c1) * f) + (get_r(c2) * (1 - f)),
						(get_g(c1) * f) + (get_g(c2) * (1 - f)),
						(get_b(c1) * f) + (get_b(c2) * (1 - f))));
}