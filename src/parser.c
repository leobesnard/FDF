/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:26:51 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/12 12:35:05 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_point(t_map *map, char *split, int i, int y)
{
	map->map[y][i].x = i * INITIAL_X_SCALE;
	map->map[y][i].y = y * INITIAL_Y_SCALE;
	map->map[y][i].z = ft_atoi(split) * INITIAL_Z_SCALE;
	map->map[y][i].color = get_color(map->map[y][i].z, split, map);
}

int	get_map_size(char *argv1, t_map *map)
{
	char	**split;
	char	*line;
	int		fd;

	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		map->max.y++;
		split = ft_split(line, ' ');
		free(line);
		if (!split)
			return (-1);
		find_max_z(split, map);
		if (get_size(split) > map->max.x)
			map->max.x = get_size(split);
		free_split(split);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	fill_map(t_map *map, int fd)
{
	char	**split;
	char	*line;
	int		x;
	int		y;

	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		x = 0;
		split = ft_split(line, ' ');
		free(line);
		if (!split)
			return (0);
		while (split[x] && x < map->max.x)
		{
			fill_point(map, split[x], x, y);
			x++;
		}
		free_split(split);
		y++;
		line = get_next_line(fd);
	}
	return (0);
}

int	map_alloc(t_map *map)
{
	int	i;

	i = 0;
	map->map = malloc(sizeof(t_point *) * (map->max.y + 1));
	if (!map->map)
		return (-1);
	map->map[map->max.y] = NULL;
	while (i < map->max.y)
	{
		map->map[i] = malloc(sizeof(t_point) * (map->max.x));
		if (!map->map[i])
		{
			free_map(*map, i);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	parser(char *argv1, t_fdf *fdf)
{
	int	fd;

	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		return (-1);
	init_max(&fdf->map);
	if (get_map_size(argv1, &fdf->map))
		return (-1);
	if (map_alloc(&fdf->map))
		return (-1);
	if (fill_map(&fdf->map, fd))
		return (-1);
	fdf->initial_map_cpy.max.x = fdf->map.max.x;
	fdf->initial_map_cpy.max.y = fdf->map.max.y;
	if (map_alloc(&fdf->initial_map_cpy))
		return (-1);
	cpy_map(fdf);
	return (0);
}
