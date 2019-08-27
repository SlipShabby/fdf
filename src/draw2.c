/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulanov <ajulanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:52:57 by ajulanov          #+#    #+#             */
/*   Updated: 2019/08/26 22:30:46 by ajulanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void		bresen_set(t_map *map)
{
	map->delta_x = map->x2 - map->x1;
	map->delta_y = map->y2 - map->y1;
	map->dx1 = 0;
	map->dy1 = 0;
	map->dx2 = 0;
	map->dy2 = 0;
	if (map->delta_x < 0)
		map->dx1 = -1;
	else
		map->dx1 = 1;
	if (map->delta_y < 0)
		map->dy1 = -1;
	else
		map->dy1 = 1;
	if (map->delta_x < 0)
		map->dx2 = -1;
	else
		map->dx2 = 1;
}

void		bresen_loop(t_map *map, int shortest, int longest)
{
	int i;
	int numerator;

	i = -1;
	numerator = 0;
	numerator = longest;
	map->longest = numerator;
	while (++i <= longest)
	{
		mlx_pixel_put(map->mlx, map->win, map->x1, map->y1,
			draw_colors(map, i));
		numerator += shortest;
		if (!(numerator < longest))
		{
			numerator -= longest;
			map->x1 += map->dx1;
			map->y1 += map->dy1;
		}
		else
		{
			map->x1 += map->dx2;
			map->y1 += map->dy2;
		}
	}
}

void		bresen(t_map *map)
{
	int longest;
	int shortest;

	bresen_set(map);
	if (map->out == 0)
		return ;
	longest = abs(map->delta_x);
	shortest = abs(map->delta_y);
	if (!(longest > shortest))
	{
		longest = abs(map->delta_y);
		shortest = abs(map->delta_x);
		if (map->delta_y < 0)
			map->dy2 = -1;
		else
			map->dy2 = 1;
		map->dx2 = 0;
	}
	bresen_loop(map, shortest, longest);
}
