/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:54:02 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/12 12:42:19 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_window(t_fdf *fdf)
{
	fdf->win.mlx = mlx_init();
	if (!(fdf->win.mlx))
		return (0);
	fdf->win.win = mlx_new_window(fdf->win.mlx, W_WIDTH, W_HEIGHT, "fdf");
	if (!(fdf->win.win))
		return (0);
	fdf->img.img = mlx_new_image(fdf->win.mlx, W_WIDTH, W_HEIGHT);
	if (!(fdf->win.win))
		return (0);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	return (1);
}

int	destroy_window(t_fdf *fdf)
{
	mlx_destroy_image(fdf->win.mlx, fdf->img.img);
	mlx_destroy_window(fdf->win.mlx, fdf->win.win);
	mlx_destroy_display(fdf->win.mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc == 2)
	{
		if (parser(argv[1], &fdf))
			return (-1);
		if (!init_window(&fdf))
			return (-1);
		initial_scale(&fdf);
		draw_map(&fdf);
		mlx_put_image_to_window(fdf.win.mlx, fdf.win.win, fdf.img.img, 0, 0);
		mlx_key_hook(fdf.win.win, key_hook, &fdf);
		mlx_mouse_hook(fdf.win.win, mouse_hook, &fdf);
		mlx_hook(fdf.win.win, 17, StructureNotifyMask, win_close1, &fdf);
		mlx_hook(fdf.win.win, 2, 1L << 0, win_close2, &fdf);
		mlx_loop(fdf.win.mlx);
		destroy_window(&fdf);
		free(fdf.win.mlx);
		free_map(fdf.map, 0);
		free_map(fdf.initial_map_cpy, 0);
	}
	return (0);
}
