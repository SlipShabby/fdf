/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulanov <ajulanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:43:19 by ajulanov          #+#    #+#             */
/*   Updated: 2019/08/26 00:26:54 by ajulanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			get_z2(t_map *map, char **split, int i, int h)
{
	char **tmp;

	get_extra(map);
	if (ft_strchr(split[i], ',') != NULL)
	{
		tmp = ft_strsplit(split[i], ',');
		map->map_z[h][i].z = ft_atoi(tmp[0]);
		map->map_z_prj[h][i] = ft_atoi(tmp[0]);
		map->map_z[h][i].color = ft_atoi_base(tmp[1] + 2, 16);
		free(tmp[0]);
		free(tmp[1]);
	}
	else
	{
		map->map_z[h][i].z = ft_atoi(split[i]);
		map->map_z[h][i].color = -1;
	}
}

void			get_extra(t_map *map)
{
	int			i;
	int			h;

	i = -1;
	h = -1;
	map->map_z_adj = ft_memalloc(sizeof(double *) * map->height);
	map->map_z_new = ft_memalloc(sizeof(double *) * map->height);
	map->map_z_prj = ft_memalloc(sizeof(double *) * map->height);
	while (++i < map->height)
	{
		map->map_z_adj[i] = ft_memalloc(sizeof(double) * map->width);
		map->map_z_new[i] = ft_memalloc(sizeof(double) * map->width);
		map->map_z_prj[i] = ft_memalloc(sizeof(double) * map->width);
	}
	while (++h < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			map->map_z_adj[h][i] = (double)map->map_z[h][i].z;
			map->map_z_new[h][i] = map->map_z_adj[h][i];
			map->map_z_prj[h][i] = map->map_z_adj[h][i];
		}
	}
}
