/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:26:51 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/06 00:36:52 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_map_size(char *argv1, t_map *map)
{
	char	**split;
	char	*line;
	int		fd;

	map->max.x = 0;
	map->max.y = 0;
	map->max.z = 0;
	fd = open(argv1, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line)
	{
		map->max.y++;
		split = ft_split(line, ' ');
		if (get_size(split) > map->max.x)
		{
			map->max.x = get_size(split);
			free_split(split); //TODO: create free_split fct ou plus smart
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	fill_map(t_map *map, int fd)
{
	char	**split;
	char	*line;
	char	x;
	char	y;
	
	x = 0;
	y = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line)
	{
		split = ft_split(line, ' ');
		ft_printf(line);
		free(line);
		while(x < map->max.x)
		{
			map->map[y][x].x = x * INITIAL_X_SCALE;
			map->map[y][x].y = y * INITIAL_Y_SCALE;
			map->map[y][x].z = ft_atoi(split[x]) * INITIAL_Z_SCALE;
			x++;
		}
		free_split(split);
		x = 0;
		y++;
		line = get_next_line(fd);
		if (!line)
			return(-1);
	}
	return (1);
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
			return (-1);
		i++;
	}
	return (0);
}

int	parser(char *argv1, t_map *map)
{
	int	fd;

	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (get_map_size(argv1, map))
		return (-1);
	if (map_alloc(map))
		return (-1);
	if (fill_map(map, fd))
		return (-1);
}
