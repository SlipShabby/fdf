/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulanov <ajulanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:23:32 by ajulanov          #+#    #+#             */
/*   Updated: 2019/08/26 00:47:56 by ajulanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			xyz_rotation(t_map *map)
{
	map->out = 1;
	z_rotation(map);
	y_rotation(map);
	x_rotation(map);
	if (map->projection == ISO)
		iso(map);
}

void			z_rotation(t_map *map)
{
	map->x00 = ((double)(map->x1) * cos(map->gamma) - \
			(double)(map->y1) * sin(map->gamma)) - (float)map->width / 2.0;
	map->y00 = ((double)(map->y1) * cos(map->gamma) + \
			(double)(map->x1) * sin(map->gamma)) - (float)map->height / 2.0;
	map->x01 = ((double)(map->x2) * cos(map->gamma) - \
			(double)(map->y2) * sin(map->gamma)) - (float)map->width / 2.0;
	map->y01 = ((double)(map->y2) * cos(map->gamma) + \
			(double)(map->x2) * sin(map->gamma)) - (float)map->height / 2.0;
	map->z00 = (double)(map->map_z_adj)[(int)(map->y1)][(int)(map->x1)];
	map->z01 = (double)(map->map_z_adj)[(int)(map->y2)][(int)(map->x2)];
	map->tmp00 = map->x00;
	map->tmp01 = map->x01;
}

void			y_rotation(t_map *map)
{
	map->x00 = (double)map->x00 * cos(map->beta) +\
			(double)map->map_z_adj[(int)(map->y1)][(int)(map->x1)] * \
			sin(map->beta);
	map->x01 = (double)map->x01 * cos(map->beta) +\
			(double)map->map_z_adj[(int)(map->y2)][(int)(map->x2)] * \
			sin(map->beta);
	map->map_z_new[(int)(map->y1)][(int)(map->x1)] = map->z00 * \
			cos(map->beta) - (double)map->tmp00 * sin(map->beta);
	map->map_z_new[(int)(map->y2)][(int)(map->x2)] = map->z01 * \
			cos(map->beta) - (double)map->tmp01 * sin(map->beta);
	map->tmp00 = map->y00;
	map->tmp01 = map->y01;
}

void			x_rotation(t_map *map)
{
	map->y00 = (double)map->y00 * cos(map->alpha) + \
			(double)(map->map_z_new)[(int)(map->y1)][(int)(map->x1)] * \
			sin(map->alpha);
	map->y01 = (double)map->y01 * cos(map->alpha) + \
			(double)(map->map_z_new)[(int)(map->y2)][(int)(map->x2)] * \
			sin(map->alpha);
	map->map_z_new[(int)(map->y1)][(int)(map->x1)] = \
			(double)map->map_z_new[(int)(map->y1)][(int)(map->x1)] * \
			cos(map->alpha) - (double)map->tmp00 * sin(map->alpha);
	map->map_z_new[(int)(map->y2)][(int)(map->x2)] = \
			(double)(map->map_z_new)[(int)(map->y2)][(int)(map->x2)] * \
			cos(map->alpha) - (double)map->tmp01 * sin(map->alpha);
	map->z00 = map->map_z_new[(int)(map->y1)][(int)(map->x1)];
	map->z01 = map->map_z_new[(int)(map->y2)][(int)(map->x2)];
}
