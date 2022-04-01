/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbesnard <lbesnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:26:51 by lbesnard          #+#    #+#             */
/*   Updated: 2022/04/01 20:11:10 by lbesnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>


int	fill_tab(t_point *tab, char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		tab[i].x = i;
		tab[i].z = atoi(split[i]);
		i++;
	}
}

int	parser(char *argv1)
{
	t_point	**tab;
	char	*line;
	char	*split;
	int		size;
	int		fd;
	int		i;
	
	i = 0;
	fd = open(fd, O_RDONLY);
	while (line != 0)
	{
		line = get_next_line(fd);
		size++;
	}
	tab = malloc(sizeof(*tab) * size);
	close(fd);
	fd = open(fd, O_RDONLY);
	size = 0;
	while (line != 0)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		tab[i] = malloc(sizeof(**tab) * get_size(split));
		tab[i] = split;
		i++;
	}
	tab[i] = NULL;
}
