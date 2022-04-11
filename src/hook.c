/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:28:37 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/11 17:48:28 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void initial_scale(t_fdf *fdf)
{
	x_translation(&fdf->map, -(fdf->map.max.x * INITIAL_X_SCALE) / 2);
	y_translation(&fdf->map, -(fdf->map.max.y * INITIAL_Y_SCALE) / 2);
	rot_x(&fdf->map, 0.5);
	rot_y(&fdf->map, -0.5);
	if (fdf->map.max.x > 100)
		zoom(&fdf->map, 0.1);
	if (fdf->map.max.x <= 100 && fdf->map.max.x > 25)
		zoom(&fdf->map, 0.6);
	if (fdf->map.max.x <= 25)
		zoom(&fdf->map, 1.1);
	
}

int	key_hook(int keycode, t_fdf *fdf)
{
	
	ft_bzero(fdf->img.addr,  (fdf->img.bits_per_pixel / 8) * W_HEIGHT * W_WIDTH);
	if (keycode == LEFT)
		x_translation(&fdf->map, -10);
	if (keycode == RIGHT)
		x_translation(&fdf->map, 10);
	if (keycode == UP)
		y_translation(&fdf->map, -10);
	if (keycode == DOWN)
		y_translation(&fdf->map, 10);
	if (keycode == ROT_Z)
		rot_z(&fdf->map, 0.05);
	if (keycode == ROT_Y)
		rot_y(&fdf->map, 0.05);
	if (keycode == ROT_X)
		rot_x(&fdf->map, 0.05);
	if (keycode == KEY_UNZOOM)
		zoom(&fdf->map, UNZOOM);
	if (keycode == KEY_ZOOM)
		zoom(&fdf->map, ZOOM);
	if (keycode == 'i')
		iso_view(fdf);
	if (keycode == 'p')
		para_view(fdf);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->win.mlx, fdf->win.win, fdf->img.img, 0, 0);
	return (0);
}

int	win_close2(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
		mlx_loop_end(fdf->win.mlx);
	return (1);
}

int	win_close1(t_fdf *fdf)
{
	mlx_loop_end(fdf->win.mlx);
	return (0);
}

int	mouse_hook(int keycode, t_fdf *fdf)
{
	/* if (keycode == MOUSE_UP)
		printf("bonjour\n"); */
	(void)keycode;
	(void)fdf;
		/* zoom(&fdf->map, ZOOM); */
	return (0);
}
