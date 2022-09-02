/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:12:14 by dirony            #+#    #+#             */
/*   Updated: 2022/09/02 22:49:33 by merlich          ###   ########.fr       */
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

# include "vector.h"
# include "camera.h"
# include "sphere.h"
# include "ray.h"
# include "matrix.h"

# include "debug.h" //чтобы выводить на экран вектора, матрицы и т.д. удалить перед сдачей


# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
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

// typedef struct s_vec3
// {
// 	float	x;
// 	float	y;
// 	float	z;
// }				t_vec3;

// typedef struct s_camera
// {
// 	t_vec3			position;
// 	t_vec3			orientation;
// 	int				fov;
// 	struct s_camera	*next;
// }					t_camera;

// typedef struct s_ambient
// {
// 	float				intensity;
// 	t_color				color;
// 	struct s_ambient	*next;
// }						t_ambient;

// typedef struct s_sphere
// {
// 	t_vec3			center;
// 	double			radius;
// 	int				color;
// 	struct s_sphere	*next;
// }					t_sphere;

typedef struct s_plane
{
	t_vec3				position;
	t_vec3				norm_vector;
	t_color				color;
	struct s_plane		*next;
}						t_plane;

typedef struct s_cylinder
{
	t_vec3				position;
	t_vec3				norm_vector;
	float				diameter;
	float				height;
	t_color				color;
	struct s_cylinder	*next;
}						t_cylinder;

// typedef struct s_ray
// {
// 	t_vec3			origin;
// 	t_vec3			direction;
// 	struct s_ray	*next;
// }					t_ray;

// typedef struct s_scene
// {
// 	int			err_flag;

// 	t_list		**lights;
// 	t_camera	*camera;
// 	t_ambient	*ambient;


// 	/* Указатели на голову списков */
// 	t_plane		*planes;
// 	t_sphere	*spheres;
// 	t_cylinder	*cylinders;

// 	// t_camera	*camera;
// 	t_ray		*ray;
// 	// t_ambient	*ambient;

// 	/* Итераторы */
// 	t_plane		*planes_head;
// 	t_sphere	*spheres_head;
// 	t_cylinder	*cylinders_head;

// 	t_camera	*camera_head;
// 	t_ray		*ray_head;
// 	t_ambient	*ambient_head;

// }				t_scene;

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

/* get_next_line.c */

char	*get_next_line(int fd);
void	ft_str_dup(const char *str, char *ptr);

/* plane_utils.c */

t_plane	*ft_plane_lstnew(char *value);
int		ft_plane_lstsize(t_plane *head);
t_plane	*ft_plane_lstlast(t_plane *head);
void	ft_plane_lstadd_front(t_plane **head, t_plane *new);
void	ft_plane_lstadd_back(t_plane **head, t_plane *new);

/* sphere_utils.c */

t_sphere	*ft_sphere_lstnew(char *value);
int			ft_sphere_lstsize(t_sphere *head);
t_sphere	*ft_sphere_lstlast(t_sphere *head);
void		ft_sphere_lstadd_front(t_sphere **head, t_sphere *new);
void		ft_sphere_lstadd_back(t_sphere **head, t_sphere *new);

/* cylinder_utils.c */

t_cylinder	*ft_cylinder_lstnew(char *value);
int			ft_cylinder_lstsize(t_cylinder *head);
t_cylinder	*ft_cylinder_lstlast(t_cylinder *head);
void		ft_cylinder_lstadd_front(t_cylinder **head, t_cylinder *new);
void		ft_cylinder_lstadd_back(t_cylinder **head, t_cylinder *new);

/* ray_utils.c */

t_ray	*ft_ray_lstnew(char *value);
int			ft_ray_lstsize(t_ray *head);
t_ray	*ft_ray_lstlast(t_ray *head);
void		ft_ray_lstadd_front(t_ray **head, t_ray *new);
void		ft_ray_lstadd_back(t_ray **head, t_ray *new);

/* camera_utils.c */

t_camera	*ft_camera_lstnew(char *value);
int			ft_camera_lstsize(t_camera *head);
t_camera	*ft_camera_lstlast(t_camera *head);
void		ft_camera_lstadd_front(t_camera **head, t_camera *new);
void		ft_camera_lstadd_back(t_camera **head, t_camera *new);

/* ambient_utils.c */

t_ambient	*ft_ambient_lstnew(char *value);
int			ft_ambient_lstsize(t_ambient *head);
t_ambient	*ft_ambient_lstlast(t_ambient *head);
void		ft_ambient_lstadd_front(t_ambient **head, t_ambient *new);
void		ft_ambient_lstadd_back(t_ambient **head, t_ambient *new);

#endif
