#ifndef MATRIX_H
# define MATRIX_H

typedef struct s_matrix
{
	float	d[4][4];
}				t_matrix;

t_vec3			multiply_by_matrix(t_vec3 p, t_matrix m);
t_matrix		look_at(t_vec3 origin, t_vec3 cam_direction);

#endif