/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:54:02 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/01 17:58:30 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "bresenham.h"
#include "colors.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	win_close(t_vars *vars)
{
	//if (keycode == 65307)
	mlx_loop_end(vars->mlx);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	printf("keyboard %c\n", keycode);
	return (0);
}

int	mouse_hook(int keycode, t_vars *vars)
{
	(void)vars;
	printf("mouse %d\n", (char)keycode);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	t_point	d;
	t_point	p1;
	t_point	p2;
	
	p1.x = W_WIDTH / 2;
	p1.y = W_HEIGHT / 2;
	p2.x = 0;
	p2.y = 0;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//draw_line(img, p1, p2, d);
	for (int i=0; i <= W_WIDTH; i += 5)
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
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 17, StructureNotifyMask, win_close, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}
