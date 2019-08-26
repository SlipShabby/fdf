/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulanov <ajulanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:34:15 by ajulanov          #+#    #+#             */
/*   Updated: 2019/08/26 01:17:33 by ajulanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			iso(t_map *map)
{
	double previous_x1;
	double previous_x2;
	double previous_y1;
	double previous_y2;

	previous_x1 = map->x00;
	previous_x2 = map->x01;
	previous_y1 = map->y00;
	previous_y2 = map->y01;
	map->x00 = (previous_x1 - previous_y1) * cos(0.523599);
	map->x01 = (previous_x2 - previous_y2) * cos(0.523599);
	map->y00 = -map->z + (previous_x1 + previous_y1) * sin(0.523599);
	map->y01 = -map->z + (previous_x2 + previous_y2) * sin(0.523599);
}

void			change_projection(int key, t_map *map)
{
	map->alpha = 0.0;
	map->beta = -0.05;
	map->gamma = 0.0;
	if (key == MAIN_I || key == NUM_3)
		map->projection = ISO;
	else if (key == MAIN_P || key == NUM_9)
		map->projection = PARALLEL;
}
