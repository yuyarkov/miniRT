/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:12:14 by dirony            #+#    #+#             */
/*   Updated: 2022/08/21 20:48:53 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>

# include <stdio.h>

# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define BUFF_SIZE 40096
# define DEF_COLOR 16777215
# define WINDOW_WIDTH 300
# define WINDOW_HEIGHT 200
# define PI_STEP 0.19634954084
# define M_LEFT 10
# define M_TOP 10
# define VALID_SYMBOLS "-,0x123456789abcdefABCDEF"
# define BASE_LOWER "0123456789abcdef"
# define BASE_UPPER "0123456789ABCDEF"

typedef struct s_dot
{
	int				alt;
	unsigned int	color;
}	t_dot;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
	int	delta_x;
	int	delta_y;
	int	sign_x;
	int	sign_y;
	int	error;
}	t_pixel;

typedef struct s_color
{
	int	a;
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_data {
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_p;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_map_data
{
	char	*filename;
	int		height;
	int		width;
	int		max_alt;
	float	rotation;
	float	rot_axe_x;
	float	rot_axe_y;
	float	rot_axe_z;
	int		offset;
	int		v_offset;
	int		zoom;
	int		h_zoom;
	int		iso_projection;
	int		adj_x;
	int		adj_y;
	t_data	*pic;
	t_dot	**map;
}	t_map_data;

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}				t_vec3;

typedef struct s_camera
{
	t_vec3		position;
	t_vec3		orientation;
	int			fov;
}				t_camera;

typedef struct s_ambient
{
	float		intensity;
	t_color		color;
}				t_ambient;

typedef struct s_scene
{
	t_list		**objects;
	t_list		**lights;
	t_camera	*camera;
	//t_ambient	*ambient;
}				t_scene;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}				t_ray;

char	*read_string_from_file(char *file_name);
int		get_width(char *s);
int		get_height(char *s);
t_dot	**get_map_from_string(char *s, t_dot **map, t_map_data *map_data);
t_dot	**parse_map(char *file_name, t_map_data *map_data);
void	*clear_map(t_dot **map, int i);




int		ft_is_hexdigit(char ch);
int		get_hex_digit(char ch);
char	*ft_atoi_hex(char *s, t_dot *dot);

void	my_mlx_pixel_put(t_data *pic, int x, int y, int color);
void	get_delta(t_pixel *pixel1, t_pixel *pixel2);
int		get_gradient(t_pixel pixel1, t_pixel pixel2);
int		get_gradient_color(int color1, int color2, float progress);
void	draw_line(t_pixel pixel1, t_pixel pixel2, t_data *pic);
t_pixel	iso_pixel(t_pixel pixel, double z, t_map_data *map_data);
void	draw_iso_grid_h(t_dot **map, t_map_data *map_data, t_data *pic);
void	draw_iso_grid_v(t_dot **map, t_map_data *map_data, t_data *pic);

int		key_h(int keycode, t_map_data *map_data);
void	parse_keycode(int keycode, t_map_data *map_data);

void	zoom_img(int keycode, t_map_data *map_data);
void	rotate_axe_x(int keycode, t_map_data *map_data);
void	rotate_axe_y(int keycode, t_map_data *map_data);
void	rotate_axe_z(int keycode, t_map_data *map_data);
void	rotate_iso_img(int keycode, t_map_data *map_data);
void	move_img(int keycode, t_map_data *map_data);
void	set_max_alt(t_dot **map, t_map_data *map_data);
void	set_def_offsets(int scale, t_map_data *map_data);
void	set_def_position(t_map_data *map_data);

t_pixel	rotate_flat(t_pixel pixel, t_map_data *map_data);
void	draw_flat_h(t_dot **map, t_map_data *map_data, t_data *pic);
void	draw_flat_v(t_dot **map, t_map_data *map_data, t_data *pic);

/* error_parser.c */

int		ft_check_input(int argc, char **argv);

/* map_parser.c */

int		check_map(char *map);

/* check_colour.c */

int		ft_check_colour(char *str);
void	ft_free_split(char **ptr);

/* check_vector.c */

int		ft_check_vector(char *str);

/* check_geometry.c */

int		ft_check_angle(int fov);
int		ft_check_ratio(float k);
int		ft_check_lparam(float l);

#endif
