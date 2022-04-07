/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:54:02 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/08 00:39:59 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_window(t_fdf *fdf)
{
	fdf->win.mlx = mlx_init(); //TODO:check retour
	if (!(fdf->win.mlx))
		return (0);
	fdf->win.win = mlx_new_window(fdf->win.mlx, W_WIDTH, W_HEIGHT, "Hello world!");//TODO:check retour
	if (!(fdf->win.win))
		return (0);
	fdf->img.img = mlx_new_image(fdf->win.mlx, W_WIDTH, W_HEIGHT);
	if (!(fdf->win.win))
		return (0);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	
	if (argc == 2)
	{
		if (parser(argv[1], &fdf.map))
			return (-1);
		if (!init_window(&fdf))
			return (-1);
		draw_map(&fdf);
		mlx_put_image_to_window(fdf.win.mlx, fdf.win.win, fdf.img.img, 0, 0);
		mlx_key_hook(fdf.win.win, key_hook, &fdf);
		mlx_mouse_hook(fdf.win.win, mouse_hook, &fdf);
		mlx_hook(fdf.win.win, 17, StructureNotifyMask, win_close1, &fdf);
		mlx_hook(fdf.win.win, 2, 1L<<0, win_close2, &fdf);
		mlx_loop(fdf.win.mlx);
		mlx_destroy_image(fdf.win.mlx, fdf.img.img);
		mlx_destroy_window(fdf.win.mlx, fdf.win.win);
		mlx_destroy_display(fdf.win.mlx);
		free(fdf.win.mlx);
		free_map(fdf.map);
	}
	return (0);
}
