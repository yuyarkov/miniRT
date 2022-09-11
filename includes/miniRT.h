/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:12:14 by dirony            #+#    #+#             */
/*   Updated: 2022/09/11 22:16:08 by merlich          ###   ########.fr       */
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

// # include "vector.h"
// # include "camera.h"
// # include "sphere.h"
// # include "ray.h"
// # include "matrix.h"

// # include "debug.h" //чтобы выводить на экран вектора, матрицы и т.д. удалить перед сдачей


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

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}				t_vec3;

typedef struct s_camera
{
	t_vec3			position;
	t_vec3			orientation;
	double			fov;
	struct s_camera	*next;
}					t_camera;

typedef struct s_ambient
{
	float				intensity;
	t_color				color;
	struct s_ambient	*next;
}						t_ambient;

typedef struct s_light
{
	t_vec3				origin;
	float				intensity;
	t_color				color;
	struct s_light	*next;
}						t_light;

typedef struct s_sphere
{
	t_vec3			center;
	float			radius;
	t_color			colour;
	int				color;
	struct s_sphere	*next;
}					t_sphere;

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

typedef struct s_ray
{
	t_vec3			origin;
	t_vec3			direction;
	struct s_ray	*next;
}					t_ray;

typedef struct s_scene
{
	int			err_flag;

	t_list		**lights;
	t_camera	*camera;
	t_ambient	*ambient;


	/* Указатели на голову списков */
	t_plane		*planes;
	t_sphere	*spheres;
	t_cylinder	*cylinders;

	// t_camera	*camera;
	t_light		*light;
	// t_ambient	*ambient;

	/* Итераторы */
	t_plane		*planes_head;
	t_sphere	*spheres_head;
	t_cylinder	*cylinders_head;

	t_camera	*camera_head;
	t_light		*light_head;
	t_ambient	*ambient_head;

}				t_scene;

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

/* get_next_line.c */

char	*get_next_line(int fd);
void	ft_str_dup(const char *str, char *ptr);

/* plane_utils.c */

t_plane	*ft_plane_lstnew(char **ptr);
int		ft_plane_lstsize(t_plane *head);
t_plane	*ft_plane_lstlast(t_plane *head);
void	ft_plane_lstadd_front(t_plane **head, t_plane *new);
void	ft_plane_lstadd_back(t_plane **head, t_plane *new);
void	ft_plane_lstdelone(t_plane *lst);
void	ft_plane_lstclear(t_plane **head);

/* sphere_utils.c */

t_sphere	*ft_sphere_lstnew(char **ptr);
int			ft_sphere_lstsize(t_sphere *head);
t_sphere	*ft_sphere_lstlast(t_sphere *head);
void		ft_sphere_lstadd_front(t_sphere **head, t_sphere *new);
void		ft_sphere_lstadd_back(t_sphere **head, t_sphere *new);
void		ft_sphere_lstdelone(t_sphere *lst);
void		ft_sphere_lstclear(t_sphere **head);

/* cylinder_utils.c */

t_cylinder	*ft_cylinder_lstnew(char **ptr);
int			ft_cylinder_lstsize(t_cylinder *head);
t_cylinder	*ft_cylinder_lstlast(t_cylinder *head);
void		ft_cylinder_lstadd_front(t_cylinder **head, t_cylinder *new);
void		ft_cylinder_lstadd_back(t_cylinder **head, t_cylinder *new);
void		ft_cylinder_lstdelone(t_cylinder *lst);
void		ft_cylinder_lstclear(t_cylinder **head);

/* light_utils.c */

t_light		*ft_light_lstnew(char **ptr);
int			ft_light_lstsize(t_light *head);
t_light		*ft_light_lstlast(t_light *head);
void		ft_light_lstadd_front(t_light **head, t_light *new);
void		ft_light_lstadd_back(t_light **head, t_light *new);
void		ft_light_lstdelone(t_light *lst);
void		ft_light_lstclear(t_light **head);

/* camera_utils.c */

t_camera	*ft_camera_lstnew(char **ptr);
int			ft_camera_lstsize(t_camera *head);
t_camera	*ft_camera_lstlast(t_camera *head);
void		ft_camera_lstadd_front(t_camera **head, t_camera *new);
void		ft_camera_lstadd_back(t_camera **head, t_camera *new);
void		ft_camera_lstdelone(t_camera *lst);
void		ft_camera_lstclear(t_camera **head);

/* ambient_utils.c */

t_ambient	*ft_ambient_lstnew(char **ptr);
int			ft_ambient_lstsize(t_ambient *head);
t_ambient	*ft_ambient_lstlast(t_ambient *head);
void		ft_ambient_lstadd_front(t_ambient **head, t_ambient *new);
void		ft_ambient_lstadd_back(t_ambient **head, t_ambient *new);
void		ft_ambient_lstdelone(t_ambient *lst);
void		ft_ambient_lstclear(t_ambient **head);

/* ft_check_params_1.c */

int			ft_check_params_a(char **ptr);
int			ft_check_params_c(char **ptr);
int			ft_check_params_l(char **ptr);

/* ft_check_params_2.c */

int			ft_check_params_sp(char **ptr);
int			ft_check_params_cy(char **ptr);
int			ft_check_params_pl(char **ptr);

t_ray	ray_create(t_vec3 origin, t_vec3 direction);
t_vec3	ray_get_direction(int x, int y, t_camera *camera);
int		ray_cast(t_ray *ray, t_scene *scene, int bounce);
t_ray	ray_from_camera(int x, int y, t_camera *camera);
t_vec3	ray_reflect(t_vec3 dir, t_vec3 normal);
t_vec3	ray_refract(t_vec3 dir, t_vec3 normal, float eta_t, float eta_i);
t_vec3	ray_get_direction(int x, int y, t_camera *camera);
t_ray	ray_from_camera(int x, int y, t_camera *camera);

t_camera		*camera_create(t_vec3 pos, t_vec3 rot, int fov);

void   			print_vector(t_vec3 vec, char *message);

typedef struct s_matrix
{
	float	d[4][4];
}			t_matrix;

t_vec3			multiply_by_matrix(t_vec3 p, t_matrix m);
t_matrix		look_at(t_vec3 origin, t_vec3 cam_direction);

t_ray			ray_create(t_vec3 origin, t_vec3 direction);
t_vec3			ray_get_direction(int x, int y, t_camera *camera);
int				ray_cast(t_ray *ray, t_scene *scene, int bounce);
t_ray			ray_from_camera(int x, int y, t_camera *camera);
t_vec3			ray_reflect(t_vec3 dir, t_vec3 normal);
t_vec3			ray_refract(t_vec3 dir, t_vec3 normal, float eta_t, float eta_i);
t_vec3			ray_get_direction(int x, int y, t_camera *camera);
t_ray			ray_from_camera(int x, int y, t_camera *camera);
t_sphere		*sphere_create(t_vec3 center, float radius);
t_vec3			sphere_get_normal(t_vec3 point, t_sphere sphere);

t_vec3			vec3_create(float x, float y, float z);
t_vec3			vector_minus(t_vec3 a, t_vec3 b);
void			vector_normalize(t_vec3 *v);
t_vec3			vec3_add(t_vec3 a, t_vec3 b);
float			vector_dot_product(t_vec3 a, t_vec3 b);
t_vec3			vec3_multiply(t_vec3 a, double b);
t_vec3			vec3_cross_product(t_vec3 a, t_vec3 b);
float			vec3_len(t_vec3 vector);
float			vec3_len2(t_vec3 v);
double			vec3_dist(t_vec3 vec1, t_vec3 vec2);


#endif
