#include "miniRT.h"

#ifndef RAY_H
# define RAY_H

typedef struct s_ray
{
	t_vec3			origin;
	t_vec3			direction;
	//struct s_ray	*next; зачем нам next?
}					t_ray;

t_ray	ray_create(t_vec3 origin, t_vec3 direction);
t_vec3	ray_get_direction(int x, int y, t_camera *camera);
int		ray_cast(t_ray *ray, t_scene *scene, int bounce);
t_ray	ray_from_camera(int x, int y, t_camera *camera);
t_vec3	ray_reflect(t_vec3 dir, t_vec3 normal);
t_vec3	ray_refract(t_vec3 dir, t_vec3 normal, float eta_t, float eta_i);


t_vec3	ray_by_x_y(int x, int y, t_scene *scene);


#endif
