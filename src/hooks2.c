/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulanov <ajulanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 23:13:11 by ajulanov          #+#    #+#             */
/*   Updated: 2019/08/26 00:27:00 by ajulanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				flatten(int key, t_map *map)
{
	int			a;
	int			b;

	a = -1;
	b = -1;
	if (key == 43)
	{
		while (++a < map->y)
		{
			b = -1;
			while (++b < map->x)
				map->map_z_adj[a][b] /= 1.05;
		}
	}
	if (key == 47)
	{
		while (++a < map->y)
		{
			b = -1;
			while (++b < map->x)
				map->map_z_adj[a][b] *= 1.05;
		}
	}
}
