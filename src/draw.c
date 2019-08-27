/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulanov <ajulanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:52:38 by ajulanov          #+#    #+#             */
/*   Updated: 2019/08/26 20:35:24 by ajulanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		transform(t_map *map)
{
	map->x1 = map->x00;
	map->y1 = map->y00;
	map->x2 = map->x01;
	map->y2 = map->y01;
	map->x1 = map->x1 * map->gap + INIT_X / 3 + map->move_x + MENU_WIDTH;
	map->y1 = map->y1 * map->gap + INIT_Y / 3 + map->move_y + MENU_WIDTH;
	map->x2 = map->x2 * map->gap + INIT_X / 3 + map->move_x + MENU_WIDTH;
	map->y2 = map->y2 * map->gap + INIT_Y / 3 + map->move_y + MENU_WIDTH;
	if (((map->x1 > INIT_X || map->x1 < 0) || (map->y1 > INIT_Y || map->y1 < 0))
	&& ((map->x2 > INIT_X || map->x2 < 0) || (map->y2 > INIT_Y || map->y2 < 0)))
		map->out = 0;
}

void		draw_y(t_map *map)
{
	map->y = 0;
	while (map->y < map->height)
	{
		map->x = 0;
		while (map->x < (map->width - 1))
		{
			map->x1 = map->x;
			map->x2 = map->x1 + 1;
			map->y1 = map->y;
			map->y2 = map->y1;
			get_colors(map);
			xyz_rotation(map);
			transform(map);
			bresen(map);
			map->x++;
		}
		map->y++;
	}
}

void		draw_x(t_map *map)
{
	map->x = 0;
	while (map->x < map->width)
	{
		map->y = 0;
		while (map->y < (map->height - 1))
		{
			map->x1 = map->x;
			map->x2 = map->x1;
			map->y1 = map->y;
			map->y2 = map->y1 + 1;
			get_colors(map);
			xyz_rotation(map);
			transform(map);
			bresen(map);
			map->y++;
		}
		map->x++;
	}
}

void		draw_map(t_map *map)
{
	draw_y(map);
	draw_x(map);
	print_menu(map);
}
