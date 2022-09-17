#ifndef PLANE_H
# define PLANE_H

typedef struct s_plane
{
	t_vec3				position;
	t_vec3				norm_vector;
	t_color				color;
	struct s_plane		*next;
}						t_plane;

#endif