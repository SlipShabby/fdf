/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulanov <ajulanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:06:27 by ajulanov          #+#    #+#             */
/*   Updated: 2019/08/26 15:03:01 by ajulanov         ###   ########.fr       */
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

	if (map->delta_x > map->delta_y)
		percentage = percent(map->x1, map->x2, map->x1 + i);
	else
		percentage = percent(map->y1, map->y2, map->y1 + i);
	red = get_light((map->color_start >> 16) & 0xFF,
					(map->color_end >> 16) & 0xFF, percentage);
	green = get_light((map->color_start >> 8) & 0xFF,
					(map->color_end >> 8) & 0xFF, percentage);
	blue = get_light(map->color_start & 0xFF, map->color_end & 0xFF,
					percentage);
	return ((red << 16) | (green << 8) | blue);
}

int		default_color(t_map *map)
{
	double percentage;

	percentage = percent(map->z_min, map->z_max, map->map_z[map->y][map->x].z);
	if (percentage < 0.2)
		return (COLOR_DISCO);
	else if (percentage < 0.4)
		return (COLOR_BRICK_RED);
	else if (percentage < 0.6)
		return (COLOR_FLAMINGO);
	else if (percentage < 0.8)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}
