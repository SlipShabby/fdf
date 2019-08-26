/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulanov <ajulanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 03:45:15 by ajulanov          #+#    #+#             */
/*   Updated: 2019/08/26 15:41:58 by ajulanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_xy(t_map *map)
{
	char	*line;
	int		count_width;
	int		i;

	while ((get_next_line(map->fd, &line)) == 1)
	{
		i = 0;
		count_width = 0;
		while (line[i])
		{
			if (line[i] == ' ')
				i++;
			else if (line[i] == '\n')
				break ;
			else
			{
				while (line[i] != '\0' && line[i] != ' ')
					i++;
				count_width++;
			}
		}
		check_first_line(map, count_width);
		map->height++;
	}
}

void	check_first_line(t_map *map, int count_width)
{
	static int first_line = 1;

	if (first_line)
	{
		map->width = count_width;
		first_line = 0;
	}
	else if (count_width != map->width)
	{
		kill_bill(ERR_MAP);
	}
}

void	get_z(t_map *map)
{
	int		i;
	char	*line;
	char	**split;

	i = -1;
	split = NULL;
	line = NULL;
	map->map_z = ft_memalloc(sizeof(t_point *) * map->height);
	while (++i < map->height)
	{
		map->map_z[i] = ft_memalloc(sizeof(t_point) * map->width);
	}
	get_z1(map, line, split, i);
}

void	get_z1(t_map *map, char *line, char **split, int i)
{
	int h;

	h = 0;
	while ((get_next_line(map->fd, &line)) > 0)
	{
		i = -1;
		split = ft_strsplit(line, ' ');
		while (++i < map->width)
		{
			map->map_z[h][i].x = i;
			map->map_z[h][i].y = h;
			get_z2(map, split, i, h);
			map->z_max = map->map_z[h][i].z > map->z_max ? \
				map->map_z[h][i].z : map->z_max;
			map->z_min = map->map_z[h][i].z < map->z_min ? \
				map->map_z[h][i].z : map->z_min;
		}
		h++;
		while (--i >= 0)
			free(split[i]);
		free(split);
		free(line);
		get_extra(map);
	}
}
