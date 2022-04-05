/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:54:02 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/06 00:15:29 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



int	win_close(t_fdf *fdf)
{
	//if (keycode == 65307)
	mlx_loop_end(fdf->win.mlx);
	return (0);
}

int	key_hook(int keycode, t_fdf *fdf)
{
	(void)fdf;
	printf("keyboard %c\n", keycode);
	return (0);
}

int	mouse_hook(int keycode, t_fdf *fdf)
{
	(void)fdf;
	printf("mouse %d\n", (char)keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	/* int fd = open("test_maps/42.fdf", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		ft_printf(line);
		free(line);
		line = get_next_line(fd);
	} */
	t_fdf	fdf;
	t_win	win;
	t_data	img;
	t_point	d;
	t_point	p1;
	t_point	p2;
	
	p1.x = W_WIDTH / 2;
	p1.y = W_HEIGHT / 2;
	p2.x = 0;
	p2.y = 0;
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
	//ft_printf("%d\n", tab[2][6].z);
	mlx_put_image_to_window(fdf.win.mlx, fdf.win.win, fdf.img.img, 0, 0);
	mlx_key_hook(fdf.win.win, key_hook, &fdf);
	mlx_mouse_hook(fdf.win.win, mouse_hook, &fdf);
	mlx_hook(fdf.win.win, 17, StructureNotifyMask, win_close, &fdf);
	mlx_loop(fdf.win.mlx);
	mlx_destroy_window(fdf.win.mlx, fdf.win.win);
	mlx_destroy_display(fdf.win.mlx);
	free(fdf.win.mlx);
}
