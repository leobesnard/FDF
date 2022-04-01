/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:28:51 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/01 16:26:01 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESENHAM_H
# define BRESENHAM_H

# include "fdf.h"

void	draw_line(t_data img, t_point p1, t_point p2, t_point d);
void	bresenham1(t_data img, t_point p1, t_point p2, t_point d);
void	bresenham2(t_data img, t_point p1, t_point p2, t_point d);
void	bresenham3(t_data img, t_point p1, t_point p2, t_point d);
void	bresenham4(t_data img, t_point p1, t_point p2, t_point d);
void	pixel_put(t_data *data, int x, int y, int color);

#endif
