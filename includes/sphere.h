#include "miniRT.h"

#ifndef SPHERE_H
# define SPHERE_H

// typedef struct s_sphere
// {
// 	t_vec3			center;
// 	double			radius;
// 	int				color;
// 	struct s_sphere	*next;
// }					t_sphere;

typedef struct s_sphere
{
	t_vec3			center;
	float			radius;
	t_color			colour;
	int				color;
	struct s_sphere	*next;
}					t_sphere;

t_sphere		*sphere_create(t_vec3 center, float radius);
t_vec3			sphere_get_normal(t_vec3 point, t_sphere sphere);
int sphere_intersect(t_vec3 ray, t_vec3 center, float radius, int color);

/* sphere_utils.c */

t_sphere	*ft_sphere_lstnew(char **ptr);
int			ft_sphere_lstsize(t_sphere *head);
t_sphere	*ft_sphere_lstlast(t_sphere *head);
void		ft_sphere_lstadd_front(t_sphere **head, t_sphere *new);
void		ft_sphere_lstadd_back(t_sphere **head, t_sphere *new);
void		ft_sphere_lstdelone(t_sphere *lst);
void		ft_sphere_lstclear(t_sphere **head);

#endif