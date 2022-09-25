/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:12:14 by dirony            #+#    #+#             */
/*   Updated: 2022/09/25 20:45:50 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>

# include <stddef.h>
# include "limits.h"

# include <stdio.h>

# include "colour.h"
# include "ambient.h"
# include "vector.h"
# include "plane.h"
# include "cylinder.h"
# include "light.h"
# include "camera.h"
# include "sphere.h"
# include "scene.h"
# include "ray.h"
# include "matrix.h"


# include "debug.h" //чтобы выводить на экран вектора, матрицы и т.д. удалить перед сдачей


# define WHITE 0x00FFFFFF
# define GREEN 0x0000FF00
# define BLACK 0x00000000
# define RED 0x00FF0000
# define BUFF_SIZE 40096
# define DEF_COLOR 16777215
# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 600
# define PI_STEP 0.19634954084
# define M_LEFT 10
# define M_TOP 10
# define VALID_SYMBOLS "-,0x123456789abcdefABCDEF"
# define BASE_LOWER "0123456789abcdef"
# define BASE_UPPER "0123456789ABCDEF"

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

char	*read_string_from_file(char *file_name);
int		get_width(char *s);
int		get_height(char *s);

int		ft_is_hexdigit(char ch);
int		get_hex_digit(char ch);
// char	*ft_atoi_hex(char *s, t_dot *dot);

void	my_mlx_pixel_put(t_data *pic, int x, int y, int color);
void	get_delta(t_pixel *pixel1, t_pixel *pixel2);
int		get_gradient(t_pixel pixel1, t_pixel pixel2);
int		get_gradient_color(int color1, int color2, float progress);
void	draw_line(t_pixel pixel1, t_pixel pixel2, t_data *pic);

/* get_next_line.c */

char	*get_next_line(int fd);
void	ft_str_dup(const char *str, char *ptr);

/* error_parser.c */

int		ft_check_input(int argc, char **argv);

/* map_parser.c */

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

/* ft_handle_button.c */

int 	ft_handle_button(int keycode, t_data *pic);
int 	ft_just_exit(t_data *pic);

/* ft_clean_map_data.c */

void	ft_clean_map_data(t_scene *scene);






#endif
