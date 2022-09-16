/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirony <dirony@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:12:14 by dirony            #+#    #+#             */
/*   Updated: 2022/09/16 19:31:55 by dirony           ###   ########.fr       */
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

# include "vector.h"
# include "camera.h"
# include "sphere.h"
# include "scene.h"
# include "ray.h"
# include "matrix.h"


# include "debug.h" //чтобы выводить на экран вектора, матрицы и т.д. удалить перед сдачей


# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define BUFF_SIZE 40096
# define DEF_COLOR 16777215
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 400
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

char	*read_string_from_file(char *file_name);
int		get_width(char *s);
int		get_height(char *s);

int		ft_is_hexdigit(char ch);
int		get_hex_digit(char ch);

void	my_mlx_pixel_put(t_data *pic, int x, int y, int color);
void	get_delta(t_pixel *pixel1, t_pixel *pixel2);
int		get_gradient(t_pixel pixel1, t_pixel pixel2);
int		get_gradient_color(int color1, int color2, float progress);
void	draw_line(t_pixel pixel1, t_pixel pixel2, t_data *pic);


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
