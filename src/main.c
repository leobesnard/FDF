/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:54:02 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/06 18:11:11 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	/* int fd = open("test_maps/pyramide.fdf", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		ft_printf(line);
		free(line);
		line = get_next_line(fd);
	} */
	t_fdf	fdf;
	
	(void)argc;
	fdf.win.mlx = mlx_init(); //TODO:check retour
	fdf.win.win = mlx_new_window(fdf.win.mlx, 1920, 1080, "Hello world!");//TODO:check retour
	fdf.img.img = mlx_new_image(fdf.win.mlx, 1920, 1080);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel, &fdf.img.line_length, &fdf.img.endian);
	//draw_line(img, p1, p2, d);
	parser(argv[1], &fdf.map);
	draw_map(&fdf);
	/* for (int i=0; i <= W_WIDTH; i += 5)
	{
		p2.x = i;
		p2.y = 0;
		draw_line(img, p1, p2, d);
		p2.y = W_HEIGHT;
		draw_line(img, p1, p2, d);
	}
	for (int i=0; i <= W_HEIGHT; i += 5)
	{
		p2.x = 0;
		p2.y = i;
		draw_line(img, p1, p2, d);
		p2.x = W_WIDTH;
		draw_line(img, p1, p2, d);
	} */
	//ft_printf("%d\n", fdf.map.map[2][6].x);
	mlx_put_image_to_window(fdf.win.mlx, fdf.win.win, fdf.img.img, 0, 0);
	mlx_key_hook(fdf.win.win, key_hook, &fdf);
	mlx_mouse_hook(fdf.win.win, mouse_hook, &fdf);
	mlx_hook(fdf.win.win, 17, StructureNotifyMask, win_close1, &fdf);
	mlx_hook(fdf.win.win, 2, 1L<<0, win_close2, &fdf);
	mlx_loop(fdf.win.mlx);
	mlx_destroy_window(fdf.win.mlx, fdf.win.win);
	mlx_destroy_display(fdf.win.mlx);
	free(fdf.win.mlx);
}
