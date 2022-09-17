#ifndef CYLINDER_H
# define CYLINDER_H

typedef struct s_cylinder
{
	t_vec3				position;
	t_vec3				norm_vector;
	float				diameter;
	float				height;
	t_color				color;
	struct s_cylinder	*next;
}						t_cylinder;

#endif