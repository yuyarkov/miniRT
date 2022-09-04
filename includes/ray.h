#include "miniRT.h"

#ifndef RAY_H
# define RAY_H

typedef struct s_ray
{
	t_vec3			origin;
	t_vec3			direction;
	struct s_ray	*next;
}					t_ray;

// typedef struct s_scene
// {
// 	t_sphere    *spheres;
//     t_list		**objects;
// 	t_list		**lights;
// 	t_camera	*camera;
// 	//t_ambient	*ambient;
// }				t_scene;

// typedef struct s_ambient
// {
// 	float				intensity;
// 	t_color				color;
// 	struct s_ambient	*next;
// }						t_ambient;

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

// typedef struct s_ambient
// {
// 	float				intensity;
// 	t_color				color;
// 	struct s_ambient	*next;
// }						t_ambient;

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

t_ray	ray_create(t_vec3 origin, t_vec3 direction);
t_vec3	ray_get_direction(int x, int y, t_camera *camera);
int		ray_cast(t_ray *ray, t_scene *scene, int bounce);
t_ray	ray_from_camera(int x, int y, t_camera *camera);
t_vec3	ray_reflect(t_vec3 dir, t_vec3 normal);
t_vec3	ray_refract(t_vec3 dir, t_vec3 normal, float eta_t, float eta_i);
t_vec3	ray_get_direction(int x, int y, t_camera *camera);
t_ray	ray_from_camera(int x, int y, t_camera *camera);

#endif