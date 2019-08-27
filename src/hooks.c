/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulanov <ajulanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:02:05 by ajulanov          #+#    #+#             */
/*   Updated: 2019/08/26 20:24:00 by ajulanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		controls(t_map *map)
{
	mlx_hook(map->win, 2, 0, key_press, map);
}

int			key_press(int key, t_map *map)
{
	int i;

	i = 0;
	if (key == PRESS_ESC)
		close_win(map);
	if (key == ZOOM_IN || key == ZOOM_IN_KEYBRD || key == ZOOM_IN_MOUSE)
		map->gap += 10;
	if (key == ZOOM_OUT || key == ZOOM_OUT_KEYBRD || key == ZOOM_OUT_MOUSE)
		map->gap -= map->gap / 2;
	if (key == 43 || key == 47)
		flatten(key, map);
	if (key == NUM_2 || key == NUM_8 || key == NUM_4 ||
		key == NUM_6 || key == NUM_1 || key == NUM_7)
		rotate(key, map);
	if (key == MOVE_UP || key == MOVE_DOWN ||
		key == MOVE_LEFT || key == MOVE_RIGHT)
		move(key, map);
	if (key == MAIN_R || key == MAIN_T)
		view(key, map);
	if (key == MAIN_P || key == MAIN_I || key == NUM_3 || key == NUM_9)
		change_projection(key, map);
	mlx_clear_window(map->mlx, map->win);
	draw_map(map);
	return (0);
}

void		view(int key, t_map *map)
{
	if (key == MAIN_R)
	{
		map->alpha = -1.57;
		map->beta = 0.0;
		map->gamma = 1.57;
		map->move_x = 30;
		map->move_y = 50;
	}
	if (key == MAIN_T)
	{
		map->alpha = 0.0;
		map->beta = 0.0;
		map->gamma = 0.0;
	}
}

void		rotate(int key, t_map *map)
{
	if (key == NUM_2)
		map->alpha += 0.05;
	if (key == NUM_8)
		map->alpha -= 0.05;
	if (key == NUM_4)
		map->beta += 0.05;
	if (key == NUM_6)
		map->beta -= 0.05;
	if (key == NUM_1)
		map->gamma += 0.05;
	if (key == NUM_7)
		map->gamma -= 0.05;
}

void		move(int key, t_map *map)
{
	if (key == MOVE_UP)
		map->move_y += 10;
	if (key == MOVE_DOWN)
		map->move_y -= 10;
	if (key == MOVE_LEFT)
		map->move_x -= 10;
	if (key == MOVE_RIGHT)
		map->move_x += 10;
}
