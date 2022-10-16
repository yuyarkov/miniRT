/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:12:14 by dirony            #+#    #+#             */
/*   Updated: 2022/10/16 20:17:48 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>

# include <stddef.h>
# include "limits.h"

# include <stdio.h>

# include "vector.h"
# include "color.h"
# include "ambient.h"
# include "light.h"
# include "camera.h"
# include "figures.h"
# include "scene.h"
# include "ray.h"

/* Colors */
# define WHITE 0x00FFFFFF
# define GREEN 0x0000FF00
# define BLACK 0x00000000
# define RED 0x00FF0000

/* Console colors */
#define RESET   "\033[0m"
#define RED_C     "\033[1;31m"
#define YELLOW_C  "\033[1;33m"
#define WHITE_C   "\033[1;37m"

/* Common params */
# define BUFF_SIZE 40096
# define DEF_COLOR 16777215
# define WIN_WIDTH 900
# define WIN_HEIGHT 600
# define PI_STEP 0.19634954084
# define M_LEFT 10
# define M_TOP 10
# define VALID_SYMBOLS "-,0x123456789abcdefABCDEF"
# define BASE_LOWER "0123456789abcdef"
# define BASE_UPPER "0123456789ABCDEF"

/* Esc button */
# define ESC 53

/* Resize figure */
# define PLUS 24
# define MINUS 27

/* Move figure */
# define W 13
# define A 0
# define S 1
# define D 2
# define Z 6
# define X 7
# define Q 12
# define E 14

/* Rotate figure */
# define F 3
# define H 4
# define T 17
# define G 5
# define R 15
# define Y 16
# define SHIFT 257
# define R_SHIFT 258
# define SPACE 49

/* Change camera`s FOV */
# define FOV_PLUS 69  // NUM_PANEL +
# define FOV_MINUS 78  // NUM_PANEL -

/* Move camera */
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define FORWARD 83  // NUM_PANEL 1
# define BACKWARD 82  // NUM_PANEL 0

/* Rotate camera */
# define ROT_UP 84  // NUM_PANEL 2
# define ROT_DOWN 91  // NUM_PANEL 8
# define ROT_LEFT 88  // NUM_PANEL 6
# define ROT_RIGHT 86  // NUM_PANEL 4
# define ROT_FRONT 92  // NUM_PANEL 9
# define ROT_BACK 89  // NUM_PANEL 7

/* Move light */
# define I 34  // UP Y_AXIS
# define K 40  // DOWN Y_AXIS
# define J 38  // LEFT X_AXIS
# define L 37  // RIGHT X_AXIS
# define U 32  // Z_AXIS
# define O 31  // Z_AXIS

/* Move/Rotate steps */
# define SIZE_STEP 10
# define MOVE_STEP 10
# define LIGHT_STEP 500
# define CAM_STEP 10
# define ROT_ANGLE PI_STEP

/* Parameters */
# define DIFF 2
# define SPEC 4
# define SHADOW -30

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

typedef struct s_data {
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_p;
	int		line_len;
	int		endian;
	t_scene	*scene_ptr;
}	t_data;

/* draw_utils.c */
void	my_mlx_pixel_put(t_data *pic, int x, int y, int color);
void	clean_scene_data(t_scene *scene);

/* get_next_line.c */

char	*get_next_line(int fd);
void	ft_str_dup(const char *str, char *ptr);

/* error_parser.c */

int		ft_check_input(int argc, char **argv);

/* map_parser.c */

int		ft_perror(char *msg);
int		check_map(t_scene *scene, char *map);

/* ft_atof.c */

float	ft_atof(char *str);

/* check_colour.c */

int		ft_check_colour(char *str);
void	ft_free_split(char **ptr);

/* check_vector.c */

int		ft_check_vector(char *str);
int		ft_check_position(char *str);

/* check_geometry.c */

int		ft_check_angle(float fov);
int		ft_check_ratio(float k);
int		ft_check_lparam(float l);

/* ft_check_params_1.c */

int		ft_check_params_a(char **ptr);
int		ft_check_params_c(char **ptr);
int		ft_check_params_l(char **ptr);

/* ft_check_params_2.c */

int		ft_check_params_sp(char **ptr);
int		ft_check_params_cy(char **ptr);
int		ft_check_params_pl(char **ptr);

/* ft_handle_buttons_1.c */

void	ft_redraw_image(t_data *pic);
int		ft_just_exit(t_data *pic);
int		ft_handle_buttons(int keycode, t_data *pic);

/* ft_handle_buttons_2.c */

void	ft_resize_figure(int step, t_data *pic);
void	ft_move_figure(int keycode, int step, t_data *pic);
void	ft_change_fov(int keycode, int step, t_data *pic);
void	ft_rotate_figure(int keycode, int angle, t_data *pic);

/* ft_handle_buttons_3.c */

void	ft_move_camera(int keycode, float step, t_data *pic);
void	ft_rotate_camera(int keycode, float angle, t_data *pic);

/* ft_handle_buttons_4.c */

void	ft_move_light(int keycode, float step, t_data *pic);
void	ft_rotate_light(int keycode, float angle, t_data *pic);

/* light_utils.c */

float	light_angle(t_vec3 normale, t_vec3 inter_point, t_scene *scene);
float	ft_spec_light(t_vec3 normale, t_vec3 direction, t_vec3 inter_point, \
																t_scene *scene);
t_vec3	get_normale(t_vec3 inter_point, t_figure *figure);
int		lightning(t_scene *scene, t_figure *figure, t_vec3 *ray, float dist);
int		is_in_shadow(t_scene *scene, t_figure *figure, t_vec3 *inter_point);

/* intersect_utils_1.c */

float	ft_plane_intersect(t_figure *plane, t_vec3 *cam_origin, \
															t_vec3 *direction);
float	ft_sphere_intersect(t_figure *sphere, t_vec3 *cam_origin, \
											t_vec3 *direction, t_discrmn box);
float	find_distance(t_figure *figure, t_vec3 *cam_origin, t_vec3 *ray);
int		ft_intersection(t_scene *scene, t_vec3 *ray);

/* intersect_utils_2.c */

float	ft_cylinder_intersect(t_figure *cyl, t_vec3 *cam_origin, \
											t_vec3 *direction, t_discrmn box);
float	ft_cylinder_intersect_2(t_figure *cyl, t_vec3 *cam_origin, \
											t_vec3 *direction, t_discrmn box);
t_vec3	ft_cylinder_norm(t_figure *cyl, t_vec3 *inter_point);

/* main.c */

void	ft_rotate_ray(t_camera *cam, t_vec3 *dir);
void	render(t_data *pic, t_scene *scene);
t_vec3	ft_rotate_dir(t_vec3 dir, t_camera *camera);
int		sphere_intersect(t_vec3 ray_original, t_scene *scene);

#endif
