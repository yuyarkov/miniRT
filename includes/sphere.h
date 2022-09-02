#include "../includes/miniRT.h"

#ifndef SPHERE_H
# define SPHERE_H

typedef struct s_sphere
{
	t_vec3			center;
	double			radius;
	int				color;
	struct s_sphere	*next;
}					t_sphere;

t_sphere		*sphere_create(t_vec3 center, float radius);
t_vec3			sphere_get_normal(t_vec3 point, t_sphere sphere);

#endif