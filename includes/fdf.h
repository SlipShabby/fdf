/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajulanov <ajulanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:59:17 by ajulanov          #+#    #+#             */
/*   Updated: 2019/08/26 15:17:11 by ajulanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../GNL/get_next_line.h"
# include "../minilibx_macos/mlx.h"

# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

/*
** ERR STRINGS
*/
# define ERR_USAGE			"usage: ./fdf [filename]"
# define ERR_MAP		    "error: invalid map"
# define ERR_CONTENT	    "error: invalid content"
# define ERR_READ	    	"error: could not read the map"
# define ERR_CREATE_MAP		"error: could not initialize map"

/*
** Initial parameters
*/
# define PRJ_NAME			"42 FDF Jaan"
# define INIT_X				1920
# define INIT_Y				1080
# define MENU_WIDTH			250
# define SCALE_Z			10

/*
** Colors
*/
# define BACKGROUND			0x222222
# define MENU_BACKGROUND	0x1E1E1E
# define TEXT_COLOR			0xEAEAEA

# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

/*
** hooks
*/
# define PRESS_ESC			53
# define ZOOM_IN			69
# define ZOOM_OUT			78
# define ZOOM_IN_MOUSE		5
# define ZOOM_OUT_MOUSE		4
# define ZOOM_IN_KEYBRD		24
# define ZOOM_OUT_KEYBRD	27
# define NUM_1				83
# define NUM_2				84
# define NUM_3				85
# define NUM_4				86
# define NUM_6				88
# define NUM_7				89
# define NUM_8				91
# define NUM_9				92
# define MOVE_UP			126
# define MOVE_DOWN			125
# define MOVE_LEFT			123
# define MOVE_RIGHT			124
# define MAIN_I				34
# define MAIN_P				35
# define MAIN_R				15
# define MAIN_T				17
# define NUM_3				85
# define NUM_9				92

/*
** ________________________________________________________________________
** STRUCTURES
*/
typedef enum			e_bool
{
	false,
	true
}						t_bool;

typedef	enum			e_projection
{
	ISO,
	PARALLEL
}						t_projection;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

typedef struct			s_map
{
	void				*win;
	void				*mlx;
	int					fd;
	int					height;
	int					width;
	int					z_min;
	int					z_max;
	t_point				**map_z;
	double				**map_z_adj;
	double				**map_z_new;
	double				x1;
	double				y1;
	double				x2;
	double				y2;
	int					delta_x;
	int					delta_y;
	int					dx;
	int					dy;
	int					dx1;
	int					dy1;
	int					dx2;
	int					dy2;
	int					x;
	int					y;
	int					i;
	int					z;
	double				x00;
	double				y00;
	double				z00;
	double				x01;
	double				y01;
	double				z01;
	double				tmp00;
	double				tmp01;
	t_projection		projection;
	int					mid_x;
	int					mid_y;
	int					side;
	int					gap;
	int					x_res;
	int					y_res;
	double				alpha;
	double				beta;
	double				gamma;
	double				z_divisor;
	int					out;
	int					color_start;
	int					color_end;
	int					color_current;
	int					longest;
	int					cur_x;
	int					cur_y;
	int					key;
	int					move_x;
	int					move_y;
}						t_map;

/*
** PROTO for fn
*/
void					kill_bill(char *s);
t_map					*create_map(void);
void					get_map(t_map *map, char *file_name);
void					check_first_line(t_map *map, int count_width);
void					get_xy(t_map *map);
void					get_z(t_map *map);
void					get_z1(t_map *map, char *line, char **split,
								int i);
void					get_z2(t_map *map, char **split, int i, int h);
void					get_z3(t_map *map, char *line, int i, int h);
void					get_extra(t_map *map);
t_bool					ft_isnumber(char *str, int base);
void					set_env(t_map *map);
void					set_default(t_map *map);
void					controls(t_map *map);
int						key_press(int key, t_map *map);
void					change_projection(int key, t_map *map);
void					move(int key, t_map *map);
void					rotate(int key, t_map *map);
void					view(int key, t_map *map);
void					flatten(int key, t_map *map);
int						close_win(void *prm);
void					draw_map(t_map *map);
void					bresen(t_map *map);
void					bresen_set(t_map *map);
void					bresen_loop(t_map *map, int shortest, int longest);
void					transform(t_map *map);
void					get_colors(t_map *map);
int						draw_colors(t_map *map, int i);
void					print_menu(t_map *map);
int						default_color(t_map *map);
double					percent(int start, int end, int current);
void					x_rotation(t_map *map);
void					y_rotation(t_map *map);
void					z_rotation(t_map *map);
void					xyz_rotation(t_map *map);
void					iso(t_map *map);
void					draw_y(t_map *map);
void					draw_x(t_map *map);

#endif
