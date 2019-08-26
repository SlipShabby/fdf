/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulanov <ajulanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:54:10 by ajulanov          #+#    #+#             */
/*   Updated: 2019/08/26 00:27:05 by ajulanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		set_env(t_map *map)
{
	set_default(map);
	controls(map);
}

/*
** set initial params for the screen and map transformation (gap)
*/

void		set_default(t_map *map)
{
	map->side = map->width > map->height ? map->width : map->height;
	map->gap = map->width > map->height ? 700 / \
		(map->width) : 700 / (map->height);
	map->x_res = 800 + map->gap * map->side;
	map->y_res = map->x_res - 300;
	map->delta_x = (map->x2 - map->x1);
	map->delta_y = (map->y2 - map->y1);
	map->alpha = 0;
	map->beta = 0;
	map->gamma = 0;
	map->z_divisor = 1;
	map->move_x = 0;
	map->move_y = 0;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->x_res, map->y_res, PRJ_NAME);
}

void		print_menu(t_map *map)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = map->mlx;
	win = map->win;
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: Scroll or +/-");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Flatten: < or >");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate: ");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "X-Axis - 2/8");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Y-Axis - 4/6");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Z-Axis - 1/7");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "xyz_rotationion");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: I Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: P Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Rigth: R Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Top: T Key");
	mlx_string_put(mlx, win, 15, y += 25, TEXT_COLOR, "Exit: ESC");
}
