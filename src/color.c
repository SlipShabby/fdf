/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulanov <ajulanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:06:27 by ajulanov          #+#    #+#             */
/*   Updated: 2019/08/26 22:34:39 by ajulanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

void	get_colors(t_map *map)
{
	map->color_start = map->map_z[(int)(map->y1)][(int)(map->x1)].color;
	map->color_end = map->map_z[(int)(map->y2)][(int)(map->x2)].color;
	if (map->color_start == -1)
	{
		if (map->map_z[(int)(map->y1)][(int)(map->x1)].z != 0)
			map->color_start = 0xffffff;
		else
			map->color_start = 0x000FFFFF;
	}
	if (map->color_end == -1)
	{
		if (map->map_z[(int)(map->y1)][(int)(map->x1)].z != 0)
			map->color_end = 0xffffff;
		else
			map->color_end = 0x000FFFFF;
	}
}

int		draw_colors(t_map *map, int i)
{
	double	percentage;
	int		red;
	int		green;
	int		blue;

	percentage = percent(0, map->longest, i);
	red = get_light((map->color_start >> 16) & 0xFF,
					(map->color_end >> 16) & 0xFF, percentage);
	green = get_light((map->color_start >> 8) & 0xFF,
					(map->color_end >> 8) & 0xFF, percentage);
	blue = get_light(map->color_start & 0xFF, map->color_end & 0xFF,
					percentage);
	return ((red << 16) | (green << 8) | blue);
}
